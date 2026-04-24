//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

void versuch04()
{
	    const double menschGroeße = 0.00170; // km
		const double plattform = 0.5557; // km
		const double erdHoehe = 6371; // km

		Vektor erdRadius(0, erdHoehe, 0);
		Vektor aussichtsPunkt(0, erdHoehe + plattform + menschGroeße, 0);
		Vektor sicht = erdRadius.sub(aussichtsPunkt); // Sicht entgegengesetzte Richtung zu erdRadius
		int schritte = 0;
		double gesamtWinkel = 0.0;
		const double beta = 0.0000000001; // rad

		while(erdRadius.winkel(sicht) > 90.0) // |/
		{
			aussichtsPunkt.rotiereUmZ(beta);
			sicht = erdRadius.sub(aussichtsPunkt);
			gesamtWinkel += beta;
			schritte++;
		}

	   double sichtWeite = sicht.laenge();
	   double sichtwinkel = gesamtWinkel * (180/M_PI); // größter Winkel umwandeln in Grad

		std::cout << std::fixed << std::setprecision(4);
		std::cout << "Sie können " << sichtWeite << " Km weit sehen." << std::endl;
		std::cout << "Sie sind " << (plattform + menschGroeße) * 1000 << " Meter hoch." << std::endl;
		std::cout << "Der Winkel beträgt " << sichtwinkel << " Grad" << std::endl;
		std::cout << "Anzahl Schritte: " << schritte << std::endl;
}

int main()
{
    
//    Vektor vector1(1, 0, 0);
//    Vektor vector2(0, 1, 0);
//
//    vector1.ausgabe();
//    vector2.ausgabe();
//
//    Vektor erdRadius(0, 0, 0);      // bitte sinnvoll initialisieren
//    Vektor aussichtsPunkt(0, 0, 0); // bitte sinnvoll initialisieren
//    Vektor sicht(0, 0, 0);
	versuch04();

    return 0;
}
