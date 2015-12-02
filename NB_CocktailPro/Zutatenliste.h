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
 * Enth�lt Zutaten
 */
class Zutatenliste
{
public:
	Zutatenliste();

        bool hatZutat(string sZutat);
private:

	vector<string> m_Zutaten;


	void ladeZutaten(string fileName);

	int getAnzahlZutaten() { return m_Zutaten.size(); };
};

#endif
