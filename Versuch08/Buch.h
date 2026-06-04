/*
 * Buch.h
 *
 *  Created on: Apr 9, 2026
 *      Author: HaiPH
 */

#ifndef BUCH_H_
#define BUCH_H_
#include "Medium.h"
#include "Person.h"

class Buch : public Medium
{
public:
	/*
	 * @brief: Konstruktor
	 *
	 * Konstruktor zum Herstellen vom Buch
	 *
	 * \param string initTitel: Titel vom Buch
	 * \param string initAutor: Autor vom Buch
	 */
	Buch(std::string initTitel, std::string initAutor);
	/*
	 * @brief: Destruktor vom Buch
	 */
	virtual ~Buch();
	/*
	 * @brief: Funktion zum ausgeben des Buches, abgeleitet vom Oberklasse
	 */
	void ausgabe(std::ostream& out) const override;

protected:
	/*
	 * @brief Autor des Buches
	 */
	std::string p_sAutor;
};

#endif /* BUCH_H_ */
