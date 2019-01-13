//===============================================================================
// Name:		bowlingsimulation.h
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:
//===============================================================================

#pragma once

#include "bowlingPlayer.h"

enum FrameResult
{
	efr_Strike = 0,
	efr_Spare,
	efr_Gutter,
	efr_None
};

struct FrameTally
{
	int m_score = 0;
	FrameResult m_frameResult = efr_None;
};

// Wrapper for the game simulation code
// generates a frame tally for a single roll,
// using the players characteristics to vary the 
// results
class BowlingSimulation
{
public:  
	BowlingSimulation();
	// Player rolls the ball
	void roll(BowlingPlayer& player, FrameTally& frameTally);
	// Frame reset
	void resetPins()
	{
		// 1 = standing, 0 = down
		m_pins = { 1,1,1,1,1,1,1,1,1,1 };
	}

protected:
	int generateReleaseLane(BowlingPlayer& player);
	void simulateRollAndScore(int releaseLane, FrameTally& tally);

private:
	array<int,10> m_pins;
};
