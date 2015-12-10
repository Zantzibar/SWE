/**
 * @(#) Waage.cpp
 */


#include "Waage.h"
#include <iostream>

/**
 * 
 */
Waage::Waage()
{
    m_fDeltaGewicht = 0.0f;
    m_fTotalgewicht = 0.0f;
}


/**
 * 
 */
void Waage::updategewicht(float differenz)
{
    m_fTotalgewicht += differenz;
    cout << "Gesamtgewicht: " << m_fTotalgewicht << " mg" << endl;
    
    this->notify();
}

/**
 * 
 */
void Waage::resetDeltaGewicht()
{
    m_fDeltaGewicht = m_fTotalgewicht;
}

/**
 * 
 */
float Waage::getTotalGewicht()
{
    return m_fTotalgewicht;
}

/**
 * 
 */
float Waage::getDeltaGwicht()
{
    return (m_fTotalgewicht - m_fDeltaGewicht);
}
