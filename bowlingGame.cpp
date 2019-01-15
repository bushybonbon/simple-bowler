//===============================================================================
// Name:		bowlingplayer.cpp
// Purpose:		simple bowling game
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:	
//===============================================================================


#include "pch.h"
#include "bowlingGame.h"

//===============================================================================

BowlingGame::BowlingGame()
{
	// //#eventually take cmd args for test harness
}

void BowlingGame::configurePlayer()
{
	m_display.welcome();
	// HC delivery and release styles
	// #note may need to tweak sim for new styles
	m_player.setPlayerCharacteristics(DeliveryStyle::eds_Stroker,ReleaseStyle::ers_TwoHanded);
}

void BowlingGame::calculateRoll(FrameTally& frameTally)
{
	m_sim.roll(m_player,frameTally);
}

void BowlingGame::resetFrame()
{
	m_sim.resetPins();
}

void BowlingGame::play()
{
	int frameCount = 0;
	FrameTally frameTally;
	while (!m_done)
	{		
		cout <<endl<< "Frame : " << frameCount << "    Score: "<<getScore()<< endl;
		cout << "========================================================= " << endl;

		cout << "Roll 1 " << endl;
		cout << "Press Enter" << endl; cin.get();
				
		calculateRoll(frameTally);
		setScore(frameTally.m_score);
		
		cout << "Roll 2 " << endl;
		cout << "Press Enter" << endl; cin.get();

		calculateRoll(frameTally);
		setScore(frameTally.m_score);

		++frameCount;
		resetFrame();
		if (frameCount == 10)
		{
			m_done = true;
		}
	}

	cout << endl<<"========================================================= " << endl;
	cout << "              Final Score: " << getScore() << endl;
	cout << "========================================================= " << endl;

	m_display.finis();
}
