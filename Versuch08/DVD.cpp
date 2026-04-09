/*
 * DVD.cpp
 *
 *  Created on: Apr 9, 2026
 *      Author: HaiPH
 */

#include "DVD.h"
#include "Medium.h"
#include "Person.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) : Medium(initTitel)
{
	p_iFreigabe = initAltersfreigabe;
	p_sGenre = initGenre;
}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

