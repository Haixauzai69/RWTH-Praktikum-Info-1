//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	front->setPrev(neuesElement);
    	neuesElement->setPrev(nullptr);
		neuesElement->setNext(front);
		front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

bool Liste::loescheStudent(int matrikelnummer)
{
	ListenElement* cursor = front;

	while (cursor != nullptr) // Die Liste wird durchgelaufen
	{
		if (cursor->getData().getMatNr() == matrikelnummer)
		{
			// Element vorne
			if (cursor == front) // falls der gesuchte Student am Anfang der Liste liegt
			{
				front = cursor->getNext();

				if (front != nullptr) // falls front nach der Inkrementation nicht auf null zeigt
				{
					front->setPrev(nullptr); // Prev Zeiger zeigt jetzt statt auf dem Element, jetzt auf nullptr, weil er jetzt front ist
				}
				else
				{
					back = nullptr; // Liste ist nur ein Element lang. Bei der Löschung muss back und front ein nullptr sein
				}
			}
			    // Element hinten
				else if (cursor == back) // falls das Element sich als letztes befindet
				{
					back = cursor->getPrev();

					if (back != nullptr) // falls back nach Dekrementation nicht auf null zeigt, dann ist es tatsächlich back
					{
						front->setNext(nullptr); // Next-Zeiger zeigt jetzt statt Element, jetzt auf nullptr, weil das nächste Element das jetzige back ist
					}
					// else wird hier nicht gebraucht, da vorher überprüft wurde ob die Liste ein Element besitzt.
				}

			    // Element Mitte
				else // sonst ist das Element irgendwo in der Liste
				{
					cursor->getPrev()->setNext(cursor->getNext()); // Next-Zeiger des vorherigen Elements zeigt jetzt auf das nächste Element des Cursors
					cursor->getNext()->setPrev(cursor->getPrev()); // Analog dazu: Prev-Zeiger des nächsten Elements zeigt jetzt auf das vorherige Element des Cursors
				}

			std::cout << "Folgender Student wird gelöscht: ";
			cursor->getData().ausgabe(); // Daten werden ausgegeben
			delete cursor; // Student wird gelöscht.
			std::cout << "\nStudent wurde erfolgreich gelöscht ";
			return true; // Programm wird da enden. Untere Argumente werden nicht mehr erreicht

		}
		cursor = cursor->getNext(); // Inkrementation
	}

	return false;
}
