//===============================================================================
// Name:		displaycomponent.cpp
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:
//===============================================================================
#include "pch.h"
#include "displayComponent.h"

void  DisplayComponent::welcome()
{
    cout<<"Welcome to simple bowler"<<endl;
	cout << "========================================================= " << endl;

}

void DisplayComponent::releaseStyle()
{
    cout << "Choose a release style"<<endl;
    cout << "(1) Traditional, (2) Two handed, (3) UFO, (4) Backup" <<endl;
}

void DisplayComponent::finis()
{
	cout << "========================================================= " << endl;
	cout << "          Thanks for playing simple bowler " << endl;
	cout << "========================================================= " << endl;

}

void DisplayComponent::deliveryStyle()
{
	cout << "Choose a delivery style" << endl;
	cout << "(1) Stroker, (2) Tweener, (3) Cranker" << endl;
}

//
//#todovoid DisplayComponent::drawPinLayout()
//{
// // Receives the m_pin layout and draws them to the console in this format:
//  // 7    8     9    0
//	//    4    5     6
//	//      2     3
//	//         1
// 
//}
//