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

void vZahlen(int iErste, int iZweite)
{
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
}

void vString()
{
	std::string sVorname;
	std::string sNachname;

	std::cout << "Vorname eingeben: " << std::endl;
	std::getline(std::cin, sVorname);

	std::cout << "Nachname eingeben: " << std::endl;
	std::getline(std::cin, sNachname);

	std::string sVornameName = sVorname + " " + sNachname;
	std::string sNameVorname = sNachname + " " + sVorname;

	std::cout << "Name, Vorname: " << sNameVorname << std::endl;
	std::cout << "Vorname, Name: " << sVornameName << std::endl;

	int iName1 = sVorname[0];
	int iName2 = sVorname[1];

	std::cout << iName1 << " " << iName2 << std::endl;

	int pos1 = sVorname[0] % 32;
	int pos2 = sVorname[1] % 32;

	std::cout << "Die Positionen im Alphabet sind jeweils: " << pos1 << " " << pos2 << std::endl;
}

int main()
{
//    int iErste = 0;
//    int iZweite = 0;
//    vZahlen(iErste, iZweite);
    vString();

	const int iZweite = 1;
    {
    	int iFeld[2] = {1,2};
    	std::cout << iFeld[0] << " " << iFeld[1] << std::endl;

    	int ispielfeld[2][3] = {{1,2,3},{4,5,6}};
    	for (int i = 0; i < 2; i++)
    	{
    		for (int j = 0; j < 3; j++)
    		{
    			std::cout << ispielfeld[i][j] << " ";
    		}
    		std::cout << std::endl;
    	}
    	const int iZweite = 1;
    	std::cout << iZweite << std::endl;
    }
    std::cout << iZweite << std::endl;

    return 0;
}
    
