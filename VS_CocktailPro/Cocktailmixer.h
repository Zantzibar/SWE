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

private:
	// zutaten.
	Zutatenliste * mZutaten;

	// mischbare Rezepte.
	MischbaresRezeptbuch * mRezepte;

	// Rezeptprozessor.
	Cocktailmixer * mProzessor;
};

#endif
