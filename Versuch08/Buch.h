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
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();
	void ausgabe(std::ostream& out) const override;

protected:
	std::string p_sAutor;
};

#endif /* BUCH_H_ */
