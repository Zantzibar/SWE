/**
 * @(#) Waage.h
 */

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"
#include "Observer.h"
/**
 * Wiegt Inhalt
 */
class Waage
{
	
public:
	// Konstruktor.
	Waage();
	//Gibt das absolute Gewicht der Waage zurueck.
	float getTotalGewicht();
	//Setzt das Delta-Gewicht zurueck auf den Aktuelle Wert der Waage
	void updateDeltaGewicht(float gewicht);
	//Fuegt der Waage Gewicht hinzu.
	void addGewicht(float gewicht);
	//entfernt Gewicht von der Waage
	void subtractGewicht(float gewicht);
	//Gibt das Delta-Gewicht der Waage zurueck.
	float getDeltaGewicht();
private:
	//Der Delta-Nullpunkt.
	float m_fDeltaGewicht;
	//Das Absolutgewicht.
	float m_fTotalgewicht;
	
	
};

#endif
