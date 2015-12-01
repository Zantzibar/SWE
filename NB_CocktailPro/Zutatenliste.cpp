/**
 * @(#) Zutatenliste.cpp
 */


#include "Zutatenliste.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

Zutatenliste::Zutatenliste()
{
	ladeZutaten("zutaten.txt");
}

// Laedt Zutaten aus einer Datei.
void Zutatenliste::ladeZutaten(string fileName)
{
	// Die Zutatendatei definiert pro Zeile eine Zutat.
	// Also: Zeile für Zeile einlesen und zur Liste hinzufügen.

	// Input-Stream anlegen.
	ifstream in;

	// Dateistream zum Einlesen öffnen.
	in.open(fileName.c_str(), ios::in);

	if (!in)
	{
		cout << "Zutatendatei konnte nicht geöffnet werden!" << endl;
		return;
	}

	cout << endl << "Lese Zutaten ein..." << endl;

	// Zeile für Zeile einlesen.
	string zeile;
	while (getline(in, zeile))
	{
		m_Zutaten.push_back(zeile);
	}

	// Dateistream schließen.
	in.close();

	cout << m_Zutaten.size() << " Zutaten wurden eingelesen!\n\n";
}

//Überprüft, ob eine bestimmte Zutat verfügbar ist.
bool Zutatenliste::hatZutat(string sZutat)
{
	for (unsigned int i = 0; i < m_Zutaten.size(); i++)
	{
		if (m_Zutaten[i] == sZutat)
			return true;
	}

	return false;
}
