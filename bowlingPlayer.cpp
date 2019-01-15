//===============================================================================
// Name:		bowlingplayer.cpp
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:	
//===============================================================================

#include "pch.h"
#include "bowlingPlayer.h"

//===============================================================================

void BowlingPlayer::updateAndGetWristFatigue(int bonus)
{
	int fatigue = 0;

	// Gamey values for ball impact and
	// lane selection influenced by release style
	// #note eventually updated every frame so I can 
	// accumulate wrist fatigue
	if ( m_releaseStyle == ReleaseStyle::ers_Traditional)
	{
		fatigue = 1;
	}
	else
		if (m_releaseStyle == ReleaseStyle::ers_TwoHanded)
		{
			fatigue = 1; //-1 
		}
		else
			if (m_releaseStyle == ReleaseStyle::ers_UFO)
			{
				fatigue = 2;
			}
			else
				if (m_releaseStyle == ReleaseStyle::ers_Backup)
				{
					fatigue = 3;
				}

	// Delivery style impacts wrist fatigue
	// which means it also contributes to poor lane selection 
	// and gutter ball probability
	if (m_deliveryStyle == DeliveryStyle::eds_Cranker)
	{
		fatigue += 2;
	}
	else
		if (m_deliveryStyle == DeliveryStyle::eds_Tweener)
		{
			fatigue += 1;
		}

	// never more than max - 5...
	m_wristFatigue = std::min(fatigue + bonus, MaxWristFatigue);
}

void BowlingPlayer::setPlayerCharacteristics(DeliveryStyle ds, ReleaseStyle rs)
{
    m_deliveryStyle = ds;
    m_releaseStyle = rs;
}

