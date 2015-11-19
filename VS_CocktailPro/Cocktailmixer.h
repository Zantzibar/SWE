/**
 * @(#) Cocktailmixer.h
 */

#ifndef COCKTAILMIXER_H_H
#define COCKTAILMIXER_H_H

#include "MischbaresRezepteBuch.h"
#include "RezepturProzessor.h"

/**
 * Initialisiert das System.
 * Bietet Userinterface.
 */
class Cocktailmixer
{
	
public:

	// Konstruktor.
	Cocktailmixer();

	// Destruktor.
	~Cocktailmixer();

	// Initialisiert den Cocktail-Mixer.
	void Initialisieren(int argc, char * argv[]);

	/**
	 * 
	 */
	void getMischbareRezepte();
	/**
	 * 
	 */
	void initialisiereSystem();
	
private:
	/**
	 * 
	 */
	MischbaresRezepteBuch *m_MischbaresRezepteBuch;
	
	/**
	 * 
	 */
	RezepturProzessor *m_Rezepturprozessor;
	
	
};

#endif
