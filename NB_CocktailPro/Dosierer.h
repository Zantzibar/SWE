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
	Dosierer(Waage * waage, string sZutat);
	/**
	 * 
	 */
	virtual void aktionAusfuehren(float menge);
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
        //abgeleitet von Klasse: Observer
	void update();
	// Notwendig zur Identifizierung des Dosierers im Vector<Geraet* > im Rezepturprozessor
        string getZutat(){return m_sZutat;};
        
private:
	
    bool m_bVentilOffen;
    int m_maxMenge;
    Waage * m_Waage;
    string m_sZutat;
    // wird nur vom Dosierer selbst benötigt
    void dosieren(float gewicht, int iTime);

};

#endif
