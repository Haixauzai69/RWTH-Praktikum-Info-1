/*
 * Buch.cpp
 *
 *  Created on: Apr 9, 2026
 *      Author: HaiPH
 */

#include "Buch.h"
#include "Medium.h"
#include "Person.h"

Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel)
{
	p_sAutor = initAutor;
}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out); // lazy, will change later if needed
	out << "Autor: " << p_sAutor << std::endl;
}

