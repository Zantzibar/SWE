/**
 * @(#) Cocktailmixer.cpp
 */

#include "stdafx.h"
#include "Cocktailmixer.h"

 // Konstruktor.
Cocktailmixer::Cocktailmixer()
{
	cout << "***********************************" << endl;
	cout << "*         CocktailPro 9000        *" << endl;
	cout << "*                                 *" << endl;
	cout << "*   Cem Dervis & Till Bade 2013   *" << endl;
	cout << "***********************************" << endl << endl;

	// Ueberpruefen, ob Turbo-Modus aktiviert wurde.
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "turbo") == 0)
		{
			MyTimer::setTurboModeEnabled(true);
			cout << "Starte im TURBO-Modus!" << endl;

			break;
		}
	}

	mZutaten = new Zutatenliste();

	mRezepte = new MischbaresRezeptbuch(mZutaten);

	cout << endl;

	mProzessor = new Rezeptprozessor(mZutaten);

	cout << endl;

	string input = "";

	while (input != "x")
	{
		int anzahlRezepte = mRezepte->getAnzahlRezepte();

		// (Gefilterte) Rezeptliste ausgeben.
		cout << "Es gibt " << anzahlRezepte << " Cocktails" << endl << endl;

		for (int i = 0; i<anzahlRezepte; i++)
		{
			Rezept* r = mRezepte->getRezept(i);
			cout << i << ". " << r->getName() << endl;
		}

		cout << endl << "Bitte auswaehlen (x zum Verlassen): ";
		cin >> input;

		if (input == "x")
			break;

		bool isInputValid = true;

		for (int i = 0; i<input.size(); i++)
		{
			if (!isdigit(input[i]))
			{
				cout << "Ungueltige Eingabe!" << endl;
				isInputValid = false;
				break;
			}
		}

		if (!isInputValid)
			continue;

		stringstream sstr;
		sstr << input;

		int inputInt;
		sstr >> inputInt;

		if (inputInt >= 0 && inputInt < anzahlRezepte)
		{
			mProzessor->zubereiten(mRezepte->getRezept(inputInt));
		}
		else
		{
			cout << "Ungueltige Eingabe!" << endl;
			continue;
		}
	}

	cout << "Bye!" << endl;
}

// Destruktor.
Cocktailmixer::~Cocktailmixer()
{
	delete mZutaten;
	delete mRezepte;
	delete mProzessor;
}