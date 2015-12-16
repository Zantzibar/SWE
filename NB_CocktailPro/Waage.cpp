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
//Neues Gesamtgewicht wird berechnet sowie notify()aus Klasse: Subject aber der spezifischen Waage zugehörig
void Waage::updategewicht(float differenz)
{
    m_fTotalgewicht += differenz;
    cout << "Gesamtgewicht: " << m_fTotalgewicht << " mg" << endl;
    // Methode veranlasst alle durch attach() hinzugefügten Observer(Dosierer) 
    //neues Gewicht gegen Abbruchbedingung zu prüfen (realisiert in Methode update() von Dosierer)
    this->notify();
}

/**
 * 
 */
// wird benötigt bei mehreren Rezeptschritten (100% der UseCases, da jedes Rezept aus mehr als einer Zutat besteht)
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
