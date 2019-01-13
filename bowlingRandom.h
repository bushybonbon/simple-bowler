//===============================================================================
// Name:		bowlingrandom.h
// Purpose:
// Author: 		Mike Ramsey
// Modified by:
// Created:
// Copyright:	(c) Mike Ramsey. All Rights Reserved.
//  			The information and source code contained herein is the
//  			exclusive property of Michael Ramsey. No part of this software
//  			may be used, reproduced, stored or distributed in any form,
//  			without explicit written authorization from Mike Ramsey.
//===============================================================================

#pragma once

#include "pch.h"

// wrapper mersenne twister 
class BowlingRandom
{
public:

  unsigned int random(int max)
  {
  	mt19937 rng(m_rd());
  	uniform_int_distribution<int> uni(0, max);
  	auto random_integer = uni(rng);
  	return random_integer;
  }

private:
  random_device m_rd;

};
