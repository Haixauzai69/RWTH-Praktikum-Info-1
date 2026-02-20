/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std; 

typedef struct 
{
    string sNachname, sVorname; 
    int iGeburtsjahr, iAlter; 
}Person; 

int main()
{
    Person nBenutzer; 
    cout << "Vorname eingeben: " << endl;
    getline(cin, nBenutzer.sVorname); 
    cout << "Nachname eingeben: " << endl;
    getline(cin, nBenutzer.sNachname); 
    cout << "Geburtsjahr eingeben: " << endl;
    cin >> nBenutzer.iGeburtsjahr; 
    cout << "Alter eingeben: " << endl;
    cin >> nBenutzer.iAlter;
    
    cout << "Vorname: " << nBenutzer.sVorname << endl;
    cout << "Nachname: " << nBenutzer.sNachname << endl;
    cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << endl;
    cout << "Alter: " << nBenutzer.iAlter << endl;

    Person nKopieEinzeln;
    nKopieEinzeln.sNachname    = nBenutzer.sNachname;
    nKopieEinzeln.sVorname     = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter       = nBenutzer.iAlter;

    // Der gesamten Struktur in einem Schritt kopieren 
    Person nKopieGesamt = nBenutzer;

    return 0;
}
