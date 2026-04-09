/*
 * Magazin.cpp
 *
 *  Created on: Apr 9, 2026
 *      Author: HaiPH
 */

#include "Magazin.h"
#include "Medium.h"
#include "Person.h"
#include "Datum.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) : Medium(initTitel)
{
	p_dAusgabe = initDatumAusgabe;
	p_sSparte = initSparte;
}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe() const
{
	Medium::ausgabe(); // lazy, will change later if needed
	std::cout << "Sparte: " << p_sSparte << std::endl;
	std::cout << "Ausgabedatum: " << p_dAusgabe << std::endl;
}

