/**
 * @(#) Cocktailmixer.h
 */

#ifndef COCKTAILMIXER_H_H
#define COCKTAILMIXER_H_H


/**
 * Initialisiert das System.
 * Bietet Userinterface.
 */
#include "Subject.h"

#include "RezepturProzessor.h"
#include "MischbaresRezepteBuch.h"
#include "Zutatenliste.h"

 //Initialisiert das System.
class Cocktailmixer //: public Subject
{
public:
	// Konstruktor.
	Cocktailmixer();

	// Destruktor.
	~Cocktailmixer();
        
	// Initialisiert den Cocktailmixer.
	void Initialisieren();

private:
	// zutaten.
	Zutatenliste * mZutaten;

	// mischbare Rezepte.
	MischbaresRezepteBuch * mRezepte;

	// Rezeptprozessor.
	RezepturProzessor * mProzessor;
};

#endif
