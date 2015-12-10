/**
 * @(#) Waage.h
 */

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"

/**
 * Wiegt Inhalt
 */
class Waage : public Subject
{
	
public:
    	/**
	 * 
	 */
	Waage();
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
	void resetDeltaGewicht();
	/**
	 * 
	 */
	void updategewicht(float differenz);

	
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
