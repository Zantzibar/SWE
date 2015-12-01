/**
 * @(#) Dosierer.h
 */

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include "Waage.h"
#include "Observer.h"
#include "Geraet.h"
/**
 * Dosiert die Jeweilige Zutat. 
 * Ventil gewisse Zeit offen/geschlossen bis Gewicht erreicht ist.
 */
class Dosierer: public Geraet, Observer
{
	
public:

	// Konstruktor
	Dosierer(Waage * waage, std::string zutat);

	//Destruktor
	~Dosierer();

	void aktionAusfuehren(float menge);
	
	void setVentilStatus(bool vState);
	
	virtual void update();
private:
	
	void dosieren(float gewicht, int timeMs);
	
	// Oeffnet das Ventil.
	void ventilOeffnen();

	// Schliesst das Ventil.
	void ventilSchliessen();

	//Die beobachtete Waage.
	Waage  * mWaage;

	// Die Zutat, die dieser Dosierer dosieren kann.
	std::string mZutat;

	// Das derzeitige Mengenlimit. Wird in update() ueberprueft.
	int mMengenLimit;

	bool isVentilOpen() { return true; };
	
	
};

#endif
