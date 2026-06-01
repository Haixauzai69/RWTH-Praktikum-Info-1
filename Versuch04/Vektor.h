//
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const;
    Vektor sub(const Vektor& input) const;
    double laenge() const;
    double skalarProd(const Vektor& input) const;
    double winkel(const Vektor& input) const;
    void rotiereUmZ(const double rad);
    Vektor operator+(Vektor input);
    
   private:
    double x;
    double y;
    double z;

};

std::ostream& operator<<(std::ostream& out, const Vektor& vector);

#endif
