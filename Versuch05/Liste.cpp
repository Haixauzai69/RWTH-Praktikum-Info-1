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
        neuesElement->setPrev(back); //aufeinander zeigen
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

bool Liste::loescheStudent(unsigned int matrikelnummer)
{
	ListenElement* cursor = front;

	while (cursor != nullptr)
	{
		if (cursor->getData().getMatNr() == matrikelnummer)
		{
			// Element vorne
			if (cursor == front) // am Anfang der Liste
			{
				front = cursor->getNext();

				if (front != nullptr)
				{
					front->setPrev(nullptr);
				}
				else
				{
					back = nullptr; // Liste ist nur ein Element lang
				}
			}
			    // Element hinten
				else if (cursor == back) // letztes Element
				{
					back = cursor->getPrev();

					if (back != nullptr)
					{
						back->setNext(nullptr);
					}

				}
			    // Element Mitte
				else
				{
					cursor->getPrev()->setNext(cursor->getNext());  // einfach mittleres Element ignorieren
					cursor->getNext()->setPrev(cursor->getPrev());
				}

			std::cout << "Folgender Student wird gelöscht: ";
			cursor->getData().ausgabe();
			delete cursor; // Student wird gelöscht.
			std::cout << "\nStudent wurde erfolgreich gelöscht ";
			return true;

		}
		cursor = cursor->getNext(); // Inkrementation
	}

	return false;
}
