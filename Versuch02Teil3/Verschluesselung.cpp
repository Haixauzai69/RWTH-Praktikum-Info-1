///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	string result; 	
	for (unsigned int i = 0; i < wort.length(); i++)
	{
		char c = wort[i];
        // Nur Buchstaben von A bis Z verarbeiten
        if (c >= 'A' && c <= 'Z')
        {
            // Index in der ersten Zeile finden
            for (int j = 0; j < 26; j++)
            {
                if (schluessel[0][j] == c)
                {
                    result += schluessel[1][j];
                    break;
                }
            }
        }
        else
        {
            // Unveränderte Zeichen (z.B. Leerzeichen, Sonderzeichen)
            result += c;
        }
    }

	return result;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	string result;
	 for (unsigned int j = 0; j < wort.length(); j++)
	 {
		 char c = wort[j];
        // Nur Großbuchstaben A–Z verarbeiten
        if (c >= 'A' && c <= 'Z')
        {
            // Index in der zweiten Zeile finden und dem Ursprungsbuchstaben zuordnen
             for (int i = 0; i < 26; i++)
             {
                if (schluessel[1][i] == c)
                {
                    result += schluessel[0][i];
                    break;
                }
            }
           
        } else {
            // Unveränderte Zeichen (z.B. Leerzeichen, Satzzeichen)
            result += c;
        }
    }
	return result;
}

int main()
{
	char secret[2][26] = {{'A','B','C','D','E','F','G','H','I','J',
		'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
	{'Q','W','E','R','T','Y','U','I','O','P','A','S','D',
		'F','G','H','J','K','L','Z','X','C','V','B','N','M'}}; // nach englischer Tastatur

	
	string word;
	cout << "Type in a text written in caplocks: " << endl;
	getline(cin,word);

	string newname = verschluesseln(secret,word); 
	cout << newname << endl;
	string oldname = entschluesseln(secret,newname);
	cout << oldname << endl;

	return 0;
}
