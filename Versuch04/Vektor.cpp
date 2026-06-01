//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>
#include <cmath>
#include <iomanip>

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

double Vektor::laenge() const
{
	return sqrt(x*x + y*y + z*z);
}

Vektor Vektor::sub(const Vektor& input) const
{
	Vektor ergebnis = Vektor(x - input.x, y - input.y, z - input.z);
	return ergebnis;
}

double Vektor::skalarProd(const Vektor& input) const
{
	return x*input.x + y*input.y + z*input.z;
}

double Vektor::winkel(const Vektor& input) const
{
	double ans = acos((this->skalarProd(input))/(this->laenge()*input.laenge()));
	return (ans*180)/M_PI;
}

void Vektor::rotiereUmZ(const double rad)
{
	double temp = x;
	x = x*cos(rad) - y*sin(rad);
	y = temp*sin(rad) + y*cos(rad);
}

Vektor Vektor::operator+(Vektor input)
{
	Vektor ergebnis = Vektor(x + input.x, y + input.y, z + input.z);
	return ergebnis;
}

std::ostream& operator<<(std::ostream& out, const Vektor& vector)
{
	vector.ausgabe();
	return out;
}
