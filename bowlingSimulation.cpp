//===============================================================================
// Name:		bowlingsimulation.cpp
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:
//===============================================================================

#include "pch.h"
#include "bowlingSimulation.h"
#include "bowlingrandom.h"

//===============================================================================

BowlingSimulation::BowlingSimulation()
{
	resetPins();
}

int BowlingSimulation::generateReleaseLane(BowlingPlayer& player)
{
	// Pin grouping:
	// 7    8     9    0
	//    4    5     6
	//      2     3
	//         1
	// Release lanes for the ball:
	// lane 1 = 7,4
	// lane 2 = 8,5,2
	// lane 3 = 9,3,1
	// lane 4 = 6,10

	const int StartingLane = 3;

	int releaseLane = StartingLane;
	int laneDeviation = StartingLane;

	// 50% chance the bias will be left or right
	BowlingRandom br;
	int prob = br.random(100);
	int bias = 1;

	if (prob < 50)
	{
		bias = -1;
	}

	// Shift the releaselane left or right
	// high wrist fatigue more variance on lane selected
	 
	int wristFatigue = min(player.getWristFatigue(), 3);
	releaseLane = StartingLane + (bias*wristFatigue);
	
	//Fake ball size by making the coarse lane sizes
	if (releaseLane != 0) { releaseLane /= 2; }
	
	// Display release lane using the players skill and fatigue to
	// impact the resulting release lane
	// #todo visually watched the above release lane get selected
	// needs to have while loop use a random cycle, and then a 
	// check to end on the correct visual frame.
	// Just a nice have.
	
	return releaseLane;
}

void BowlingSimulation::roll(BowlingPlayer& player, FrameTally& frameTally)
{
	
	// update players wrist fatigue
	player.updateAndGetWristFatigue();

	// gutter ball check
	// 20% base chance of gutter
	// Would be neat to add the overall length  into the gutter calc
	BowlingRandom br;
	int gutterVal = 20 + (player.getWristFatigue() * 10);
	int prob = br.random(100);
	if (prob <= gutterVal)
	{
		cout << "Gutter !!!" << endl<<endl;
		frameTally.m_frameResult = FrameResult::efr_Gutter;
	}
	else
	{
		int releaseLane = generateReleaseLane(player);

		// check for a strike - sweet spot (favors right handed)
		if (releaseLane == 2)
		{
			int strikeProb = br.random(100);
			if (strikeProb < player.getWristFatigue() * 10) //low wrist fatigue
			{
				cout <<endl << "Strike!!!" << endl;
				frameTally.m_frameResult = FrameResult::efr_Strike;
				frameTally.m_score += 10;
			}
			else
			{
				simulateRollAndScore(releaseLane, frameTally);
			}
		}
		else
		{
			simulateRollAndScore(releaseLane, frameTally);
		}		
	}
}


void BowlingSimulation::simulateRollAndScore(int releaseLane, FrameTally& tally)
{
	// Pin grouping:
	// 7    8     9    0
	//    4    5     6
	//      2     3
	//         1
	// Release lanes for the ball:
	// lane 1 = 7,4
	// lane 2 = 8,5,2
	// lane 3 = 9,3,1
	// lane 4 = 6,10
	array<array<int, 3>,4> lanes = { { { 7,4,-1 },{ 8,5,2},{ 9,3,1},{ 6,10,-1 }} };

	// Random pin selection from group for knockdowns - ideally use the ball speed (#todo)
	BowlingRandom br;
	int releaseLaneShift= br.random(100);
	int newReleaseLane = releaseLane; 
	if (releaseLaneShift < 75)
	{	
		if (releaseLaneShift > 50)
		{
			newReleaseLane = releaseLane + 1;
		}
		else
		{
			newReleaseLane = releaseLane - 1;
		}
		
		if (newReleaseLane < 0 || newReleaseLane>4)//crazy roll
		{
			newReleaseLane = br.random(3);
		}
	}
	// only blocks (of pins) that are non -1 contribute to the score
	int block1 = lanes[newReleaseLane][0];
	int block2 = lanes[newReleaseLane][1];
	int block3 = lanes[newReleaseLane][2];
	array<int, 3> pins = { lanes[newReleaseLane][0], lanes[newReleaseLane][1], lanes[newReleaseLane][2] };
	
	int pinHitCount = 1+br.random(2);
	int actualHitCount = 0; // some pins will have potentially already been knocked down , so ignore those slots
	for (int i = 0; i < pinHitCount; ++i)
	{
		int pin = pins.at(i); // pin lane values are actual pin designations from rules, this makes the # array friendly
		pin -= 1;
		if ((pin>0) && (m_pins.at(pin) == 1)) 
		{ 
			m_pins.at(pin) = 0;
			++actualHitCount; 
			cout << "Pin " << pin << " goes down " << endl;
		} //knockdown
	}
	if (actualHitCount == 0)
	{
		cout << "Miss!" << endl;
	}
	// Score the hits
	tally.m_score += actualHitCount;
	
	// #todo, sorry no bonus/spare scoring :-(	
	// #todo Generate potential collateral knockdowns
}