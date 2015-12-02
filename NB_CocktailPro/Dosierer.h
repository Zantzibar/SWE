/**
 * @(#) Dosierer.h
 */

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include "Geraet.h"
#include "Observer.h"
#include "Waage.h"
#include <string>

/**
 * Dosiert die Jeweilige Zutat. 
 * Ventil gewisse Zeit offen/geschlossen bis Gewicht erreicht ist.
 */
class Dosierer: public Geraet, Observer
{
	
public:

	// Konstruktor
	Dosierer(Waage * waage, string zutat);
        //Destruktor
	~Dosierer();
	bool isVentilOpen()const {return m_bVentilOffen;}
        std::string getZutat() const;
        void aktionAusfuehren(float menge);
	void setVentilStatus(bool bState);
	virtual void update();
private:
	
	void dosieren(float gewichtProStk, int timeMs);
	//Die beobachtete Waage.
	Waage  * mWaage;
	// Die Zutat, die dieser Dosierer dosieren kann.
	string mZutat;
	// Das derzeitige Mengenlimit. Wird in update() ueberprueft.
	int mMengenLimit;
        bool m_bVentilOffen;
};

#endif
