/**
 * @(#) Waage.h
 */

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"
/**
 * Wiegt Inhalt
 */
class Waage: Subject
{
	
public:
	/**
	 * 
	 */
	float getDeltaGwicht();
	/**
	 * 
	 */
	float getTotalGewicht();
	/**
	 * 
	 */
	void updateDeltaGewicht(float gewicht);
	/**
	 * 
	 */
	void updategewicht(float differenz);
	/**
	 * 
	 */
	Waage();
	
private:
	/**
	 * 
	 */
	float m_fDeltaGewicht;
	
	/**
	 * 
	 */
	float m_fTotalgewicht;
	
	
};

#endif
