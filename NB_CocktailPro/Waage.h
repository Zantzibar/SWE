/**
 * @(#) Waage.h
 */

#ifndef WAAGE_H_H
#define WAAGE_H_H

/**
 * Wiegt Inhalt
 */
class Waage
{
	
public:
	/**
	 * 
	 */
	void getTotalGewicht();
	/**
	 * 
	 */
	void updateDeltaGewicht(float gewicht);
	/**
	 * 
	 */
	void updategewicht(float gewicht);
	
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
