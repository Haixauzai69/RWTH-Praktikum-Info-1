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
	/*
	 * @brief: Konstruktor
	 *
	 * Konstruktor
	 *
	 * \param string initTitel: Titel
	 * \param Datum initDatumAusgabe: Erscheinungsdatum
	 * \param string initSparte: Sparte
	 */
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	/*
	 * @brief: Destruktor
	 */
	virtual ~Magazin();
	/*
	 *  @brief Ausgabe-Funktion, abgeleitet vom Oberklasse Medium
	 */
	void ausgabe(std::ostream& out) const override;
	/*
	 *  @brief Ausleihen-Funktion, abgeleitet vom Oberklasse Medium
	 */
	bool ausleihen(Person person, Datum ausleihdatum) override;
protected:
	/*
	 * @brief Ausgabe
	 */
	Datum p_dAusgabe;
	/*
	 * @brief Sparte
	 */
	std::string p_sSparte;
};

#endif /* MAGAZIN_H_ */
