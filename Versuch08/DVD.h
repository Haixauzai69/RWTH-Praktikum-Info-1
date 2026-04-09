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
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();
protected:
	int p_iFreigabe;
	std::string p_sGenre;
};

#endif /* DVD_H_ */
