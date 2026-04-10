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

void DVD::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out); // lazy, will change later if needed
	out << "Mindestalter: " << p_iFreigabe << std::endl;
	out << "Genre: " << p_sGenre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	if(((person.getGeburtsdatum() - ausleihdatum)/12) < p_iFreigabe) // geteilt durch 12 weil im Jahr berechnet
	{
		std::cout << "Nutzer nicht alt genug, um dieses DVD auszuleihen" << std::endl;
		return false;
	}
	else
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}
}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

