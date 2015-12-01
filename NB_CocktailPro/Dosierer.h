/**
 * @(#) Dosierer.h
 */

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include "Waage.h"

/**
 * Dosiert die Jeweilige Zutat. 
 * Ventil gewisse Zeit offen/geschlossen bis Gewicht erreicht ist.
 */
class Dosierer
{
	
public:

	// Konstruktor
	Dosierer();	

	//Destruktor
	~Dosierer();

	/**
	 * 
	 */
	void aktionAusfuehren(float menge);
	/**
	 * 
	 */
	void setVentilStatus(bool vState);
	
private:
	/**
	 * 
	 */
	void  dosieren(float gewicht, int timems);
	/**
	 * 
	 */
	//Waage * g_Waage;
	
	/**
	 * 
	 */
	bool isVentilOpen() { return true; };
	
	
};

#endif
