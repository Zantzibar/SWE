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
class Dosierer: public Geraet, Observer
{
	
public:
	/**
	 * 
	 */
	virtual void aktionAusfuehren(float menge);
	/**
	 * 
	 */
	Dosierer(const Waage * waage, string sZutat);
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
	
        string getZutat(){return m_sZutat;};
private:
	
	void  dosieren(float gewicht, int timems);
	
	bool m_bVentilOffen;
	
	int m_maxMenge;
        
	Waage * m_Waage;
	
        string m_sZutat;
	
};

#endif
