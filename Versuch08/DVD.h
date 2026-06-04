/*
 * DVD.h
 *
 *  Created on: Apr 9, 2026
 *      Author: HaiPH
 */

#ifndef DVD_H_
#define DVD_H_
#include "Medium.h"
#include "Person.h"

class DVD : public Medium
{
public:
	/*
	 * @brief: Konstruktor
	 *
	 * Konstruktor zum Herstellen vom DVD
	 *
	 * \param string initTitel: Titel vom DVD
	 * \param int initAltersfreigabe: Mindestalter fuer Zugang
	 * \param string initGenre: Genre vom DVD
	 */
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	/*
	 * @brief: Destruktor vom Buch
	 */
	virtual ~DVD();
	/*
	 *  @brief Ausleihen-Funktion, abgeleitet vom Oberklasse Medium
	 */
	bool ausleihen(Person person, Datum ausleihdatum) override;
	/*
	 *  @brief Ausgabe-Funktion, abgeleitet vom Oberklasse Medium
	 */
	void ausgabe(std::ostream& out) const override;
protected:
	/*
	 * @brief Freigabealter
	 */
	int p_iFreigabe; // im Jahr gegeben
	/*
	 * @brief Gerne vom DVD
	 */
	std::string p_sGenre;
};

#endif /* DVD_H_ */
