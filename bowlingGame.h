//===============================================================================
// Name:		bowlinggame.h
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:
//===============================================================================



#pragma once

#include "bowlingPlayer.h"
#include "bowlingSimulation.h"
#include "displayComponent.h"


class BowlingGame
{
    public:
        BowlingGame();
		// Req: calculateRoll
		// invokes the underlying bowling sim object
        void calculateRoll(FrameTally& frameTally);
		// configure the player
        void configurePlayer();
		// play the game
		void play();
		// reset pins in sim
		void resetFrame();

		//set/getters
		void setScore(int score) { m_score = score; }
		int getScore() { return m_score.load(); }

    private:
        BowlingPlayer       m_player;
        BowlingSimulation   m_sim;
        DisplayComponent    m_display;
        bool                m_done = false;
		atomic<int>			m_score = 0;

};
