//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    std::cout << "Eingabe erster Zahl: " << std::endl;
    std::cin >> iErste;
    std::cout << "Eingabe zweiter Zahl: " << std::endl;
    std::cin >> iZweite;

    int iSumme = iErste + iZweite;
    std::cout << "Die Summe (int) ist: " << iSumme << std::endl;
    int iQuotient = iErste/iZweite;
    std::cout << "Die Quotient (int) ist: " << iQuotient << std::endl;

    double dSumme = iErste + iZweite;
    std::cout << "Die Summe (double) ist: " << dSumme << std::endl;
    double dQuotient = iErste/iZweite;
    std::cout << "Die Quotient (double) ist: " << dQuotient << std::endl;
    
    double dSummeCast = static_cast<double>(iErste) + static_cast<double>(iZweite);
    std::cout << "Die Summe (double cast) ist: " << dSummeCast << std::endl;
    double dQuotientCast = static_cast<double>(iErste)/static_cast<double>(iZweite);
    std::cout << "Die Quotient (double cast) ist: " << dQuotientCast << std::endl;

    
    return 0;
}
    
