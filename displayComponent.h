//===============================================================================
// Name:		displaycomponent.h
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:
//===============================================================================

#pragma once

//Handles any drawing to the console,
//e.g. release lane,
// pin layout
//
class DisplayComponent
{
public:
	// Welcome text
    void welcome();
	// Release style text - selection made
    void releaseStyle(); 
	// Delivery style text - selection made
	void deliveryStyle();
	// finis message
	void finis();
protected:
	//#todo voidDrawPinLayout();
};
