/**
 * @(#) Dosierer.h
 */

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include "Geraet.h"
#include "Observer.h"
#include "Waage.h"
#include "string.h"
/**
 * Dosiert die Jeweilige Zutat. 
 * Ventil gewisse Zeit offen/geschlossen bis Gewicht erreicht ist.
 */
class Dosierer: Geraet, Observer
{
	
public:
	/**
	 * 
	 */
	void aktionAusfuehren(float menge);
	/**
	 * 
	 */
	Dosierer(const Waage * waage, ::string sZutat);
	/**
	 * 
	 */
	bool isVentilOffen();
	/**
	 * 
	 */
	void setVentilOffen(bool vState);
	/**
	 * 
	 */
	void update();
	
private:
	/**
	 * 
	 */
	void  dosieren(float gewicht, int timems);
	/**
	 * 
	 */
	bool m_bVentilOffen;
	
	/**
	 * 
	 */
	Waage * m_Waage;
	
	
};

#endif
