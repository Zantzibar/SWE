/**
 * @(#) Dosierer.cpp
 */


#include "Dosierer.h"
/**
 * 
 */
void Dosierer::aktionAusfuehren(float menge)
{
	
}

/**
 * 
 */
void Dosierer:: dosieren(float gewicht, int timems)
{
    m_Waage->attach(this);
    
    setVentilOffen(true);
    while(isVentilOffen() == true)
    {
    // dosiere bis  abbruch...Ventil wird geschlossen über Waage->addgewicht->Subjekt->Observer->Update->UpdatevonDosierer->setventilOffen=true)
    m_Waage->updategewicht(gewicht);
    
    }
    m_Waage->detach(this);
}

/**
 * 
 */
void Dosierer::setVentilOffen(bool vState)
{
	m_bVentilOffen = vState;
}

/**
 * 
 */
Dosierer::Dosierer(const Waage * waage, ::string sZutat)
{
    m_maxMenge = 0; // vorlaeufig.. muss menge noch unter aktion ausfuehren bekommen....diese wiederum ruft dosiern auf und setztmax menge = maxMenge
    
}

/**
 * 
 */
bool Dosierer::isVentilOffen()
{
	return m_bVentilOffen;
}

// Methode der klasse update wird überschrieben. bei jedem aufruf (passiert wenn gewicht hinzugefügt wird ( wieviel wird pro einheit hinzugefügt?))
// wennn maxgewicht erreicht dann wir das ventil geschlossen
void Dosierer::update()
{
    
    if ( m_Waage->getDeltaGwicht() >= m_maxMenge)
    {
         // dann schliesse das Ventil
        setVentilOffen(false);
    }
}

