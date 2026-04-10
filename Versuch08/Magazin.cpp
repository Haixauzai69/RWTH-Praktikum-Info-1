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

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	// if (date - date <= 0)
//	 cannot be borrowed, return false. else Medium::ausleihen() return true
	if(ausleihdatum - p_dAusgabe <= 0)
	{
		std::cout << "Neuste Ausgabe Magazin! Darf nicht ausgeliehen werden!" << std::endl;
		return false;
	}
	else
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}
}

