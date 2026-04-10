/*
 * Magazin.h
 *
 *  Created on: Apr 9, 2026
 *      Author: HaiPH
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_
#include "Medium.h"
#include "Person.h"
#include "Datum.h"

class Magazin : public Medium
{
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();
	void ausgabe() const override;
	bool ausleihen(Person person, Datum ausleihdatum) override;
protected:
	Datum p_dAusgabe;
	std::string p_sSparte;
};

#endif /* MAGAZIN_H_ */
