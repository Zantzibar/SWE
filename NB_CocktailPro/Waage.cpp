/**
 * @(#) Waage.cpp
 */


#include "Waage.h"

Waage::Waage() : m_fTotalgewicht(0.0f), m_fDeltaGewicht(0.0f)
{
	// Leer
}

void Waage::addGewicht(float gewicht)
{
    m_fTotalgewicht += gewicht;
    this->notify();
}

void Waage::subtractGewicht(float gewicht)
{
	addGewicht(-gewicht);
}

void Waage::updateDeltaGewicht(float gewicht)
{
	m_fDeltaGewicht = m_fTotalgewicht;
}

float Waage::getDeltaGewicht()
{
	return (m_fTotalgewicht - m_fDeltaGewicht);
}

float Waage::getTotalGewicht()
{
	return m_fTotalgewicht;
}

