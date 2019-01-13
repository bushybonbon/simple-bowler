//===============================================================================
// Name:		bowlingplayer.h
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:	
//===============================================================================


#pragma once

static int MaxWristFatigue = 5;

enum ReleaseStyle
{
    ers_Traditional = 0,
    ers_TwoHanded,
    ers_UFO,
    ers_Backup
};

enum DeliveryStyle
{
    eds_Stroker = 0,
    eds_Tweener,
    eds_Cranker
};

class BowlingPlayer
{
    public:
        BowlingPlayer(){} // leave it open to cfg from cmdline args
		// Set the players characteristics
        void setPlayerCharacteristics(DeliveryStyle ds, ReleaseStyle rs);
		// Update the players wrist fatigue, currently only once but could be dynamic
		// after multiple attempts
		void updateAndGetWristFatigue(int bonus=0);
		// Accessor for wrist fatigue
		int getWristFatigue() { return m_wristFatigue; }
		// Players delivery style bias amount
		int getDeliveryStyleBias();

    private:
		DeliveryStyle m_deliveryStyle   = eds_Stroker;
		ReleaseStyle m_releaseStyle     = ers_Traditional;
		int m_wristFatigue = 0; 

};
