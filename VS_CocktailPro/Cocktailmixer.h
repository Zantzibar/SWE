/**
 * @(#) Cocktailmixer.h
 */

#ifndef COCKTAILMIXER_H_H
#define COCKTAILMIXER_H_H


/**
 * Initialisiert das System.
 * Bietet Userinterface.
 */
#include "RezepturProzessor.h"
#include "MischbaresRezepteBuch.h"
#include "Zutatenliste.h"

 //Initialisiert das System.
class Cocktailmixer
{
public:
	// Konstruktor.
	Cocktailmixer();

	// Destruktor.
	~Cocktailmixer();

	// Initialisiert den Cocktailmixer.
	void Initialisieren(int argc, char * argv[]);

private:
	// zutaten.
	Zutatenliste * mZutaten;

	// mischbare Rezepte.
	MischbaresRezepteBuch * mRezepte;

	// Rezeptprozessor.
	Cocktailmixer * mProzessor;
};

#endif
