//===============================================================================
// Name:		appmain.cpp
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:
//===============================================================================


#include "pch.h"
#include "bowlingGame.h"


int main()
{
	BowlingGame theGame;
	theGame.configurePlayer();
	theGame.play();
	return 0;
}
