/**
 * @(#) Cocktailmixer.cpp
 */


#include "Cocktailmixer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>

 // Konstruktor.
Cocktailmixer::Cocktailmixer()
{

}

// Destruktor.
Cocktailmixer::~Cocktailmixer()
{
}

// Initialisiert den Cocktail-Mixer.
void Cocktailmixer::Initialisieren(int argc, char * argv[])
{
/*	mZutaten = new Zutatenliste();

	mRezepte = new MischbaresRezepteBuch(mZutaten);

	cout << endl;

	mProzessor = new RezepturProzessor(mZutaten);

	cout << endl;

	int input = -1;

	while (input != 0)
	{
		int anzahlRezepte = mRezepte->getAnzahlRezepte();

		// (Gefilterte) Rezeptliste ausgeben.
		cout << "Es gibt " << anzahlRezepte << " Cocktails" << endl << endl;

		for (int i = 0; i < anzahlRezepte; i++)
		{
			Rezept* r = mRezepte->getRezept(i);
			cout << i << ". " << r->getName() << endl;
		}

		cout << endl << "Bitte auswaehlen (0 zum Verlassen): ";
		cin >> input;

		if (input == 0)
			break;

		if (input < anzahlRezepte)
		{
			mProzessor->zubereiten(mRezepte->getRezept(input));
		}
		else
		{
			cout << "Ungueltige Eingabe!" << endl;
			continue;
		}
	}

	cout << "Bye!" << endl;*/
}
