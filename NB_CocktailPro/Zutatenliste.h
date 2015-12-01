/**
 * @(#) Zutatenliste.h
 */

#ifndef ZUTATENLISTE_H_H
#define ZUTATENLISTE_H_H

#include <string>
#include <iostream>

#include <vector>

using namespace std;

/**
 * Enthält Zutaten
 */
class Zutatenliste
{
public:
	Zutatenliste();


private:

	vector<string> m_Zutaten;


	void ladeZutaten(string fileName);
	bool hatZutat(string sZutat);
	int getAnzahlZutaten() { return m_Zutaten.size(); };
};

#endif
