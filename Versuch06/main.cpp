/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 6: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
//        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
//        studentenListe.push_back(student);
//        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
//        studentenListe.push_back(student);
//        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
//        studentenListe.push_back(student);
//        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
//        studentenListe.push_back(student);
//        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
//        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenbank löschen" << std::endl
				  << "(6): Datenelement vorne hinzufuegen" << std::endl
				  << "(7): Daten aus einer Datei einlesen" << std::endl
				  << "(8): Daten in eine Datei sichern" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front(); // front ablesen()
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
//                    studentenListe.ausgabeVorwaerts();
                    for(auto it = studentenListe.begin(); it < studentenListe.end(); it++)
                    {
                    	it->ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
// Datenbank in umgekehrter Reihenfolge ausgeben
            case '4':
				if(!studentenListe.empty())
				{
					std::cout << "Inhalt der Liste in ruecklaufender Reihenfolge:" << std::endl;
                    for(auto it = studentenListe.end() - 1; it >= studentenListe.begin(); --it)
                    {
                    	it->ausgabe();
                    }
				}
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
				break;

			// Student löschen
			case '5':
				if(!studentenListe.empty())
				{
					unsigned int matNr;
					std::cout << "Matrikelnummer eingeben: ";
					std::cin >> matNr;
					for(auto it = studentenListe.begin(); it < studentenListe.end(); it++)
					{
						if(it->getMatNr() == matNr)
						{
							std::cout << "Dieser Student wird gelöscht: " << std::endl;
							it->ausgabe();
							studentenListe.erase(it);
							break;
						}
						else
						{
							std::cout << "Student wurde nicht gefunden" << std::endl;
						}
					}

				}
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
				break;
// 		Datenelement vorne hinzufuegen
			case'6':
				if(!studentenListe.empty())
				{
					std::string name, geburtsdatum, adresse;
					int matNr;

					std::cout << "Name eingeben: " << std::endl;
					std::getline(std::cin, name);
					std::cout << "Geburtsdatum eingeben: " << std::endl;
					std::getline(std::cin, geburtsdatum);
					std::cout << "Adresse eingeben: " << std::endl;
					std::getline(std::cin, adresse);
					std::cout << "Matrikelnummer eingeben: " << std::endl;
					std::cin >> matNr;

					student = Student(matNr, name, geburtsdatum, adresse); // Methode um neuen Student zu erstellen
					studentenListe.insert(studentenListe.begin(), student); // Student wird als Front der Liste eingetragen
				}
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
				break;
// 			Daten aus einer Datei ablesen
			case '7':
			{
				studentenListe.clear();
				std::string dateiName;
				std::cout << "Name der Datei: ";
				std::getline(std::cin, dateiName);

				std::ifstream f(dateiName);

				if(!f)
				{
					std::cout << "Datei wurde nicht gefunden" << std::endl;
					break;
				}

				std::string line;

				while(std::getline(f, line))
				{
					if(line.empty())
					{
						continue;
					}
					int nr = std::stoi(line);

					std::string name;
					std::string geburtstag;
					std::string adresse;

					std::getline(f, name);
					std::getline(f, geburtstag);
					std::getline(f, adresse);

					Student stu = Student(nr, name, geburtstag, adresse);

					studentenListe.push_back(stu);
				}
			}
				break;
//				Daten in eine Datei sichern
			case '8':
			{
				if(!studentenListe.empty())
				{
					std::string filename;
					std::cout << "Enter file name for saving (.txt): ";
					std::getline(std::cin, filename);
					std::ofstream ausgabe;
					ausgabe.open(filename);
					for(auto it = studentenListe.begin(); it != studentenListe.end(); it++)
					{
						ausgabe << it->getMatNr() << std::endl;
						ausgabe << it->getName() << std::endl;
						ausgabe << it->getGeburtstag() << std::endl;
						ausgabe << it->getAdresse() << std::endl;
					}
					ausgabe.close();
					std::cout << "Information gespeichert in " << filename << std::endl;
				}
				else
				{
					std::cout << "Liste ist leer!" << std::endl;
				}
			}
			break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
