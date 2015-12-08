/**
 * @(#) Waage.cpp
 */


#include "Waage.h"
/**
 * 
 */
void Waage::updategewicht(float differenz)
{
    m_fTotalgewicht += differenz;
    this->notify();
}

/**
 * 
 */
void Waage::updateDeltaGewicht(float gewicht)
{
	
}

/**
 * 
 */
float Waage::getTotalGewicht()
{
	return 0;
}

/**
 * 
 */
float Waage::getDeltaGwicht()
{
	return 0;
}

/**
 * 
 */
Waage::Waage()
{
	
}

