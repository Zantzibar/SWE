/**
 * @(#) Dosierer.cpp
 */


#include "Dosierer.h"
#include "Timer.h"
#include <iostream>

/**
 * 
 */
Dosierer::Dosierer(Waage * waage, string sZutat)
{
    m_maxMenge = 0; // vorlaeufig.. muss menge noch unter aktion ausfuehren bekommen....diese wiederum ruft dosiern auf und setztmax menge = maxMenge
    m_sZutat = sZutat;
    m_Waage = waage;
    mAktion = sZutat; // doppelt rein
    cout << "Dosierer: " << getZutat() << " initialisiert" << endl;
}

/**
 * 
 */
void Dosierer::aktionAusfuehren(float menge)
{
    m_maxMenge = menge;
    m_Waage->resetDeltaGewicht(); // tara
    
    string sZutat = getZutat();
    
    float gewichtProStck = 0.0f;
    int timems = 1000; // Stimmt das so ?

    if(sZutat == "Limettenstuecke")
    {
        gewichtProStck = 10.0f;
    }
    else if(sZutat == "Eis")
    {
        gewichtProStck = 20.0f;        
    }
    else
    {
        gewichtProStck = 1.0f;
        timems = 250;
    }

    dosieren(gewichtProStck, timems);
}

/**
 * 
 */
void Dosierer::dosieren(float gewicht, int timems)
{
    m_Waage->attach(this);
    
    Timer aTimer;
    
    setVentilOffen(true);
    cout << "Ventil " << getZutat() << ": geoeffnet." << endl;
    while(isVentilOffen() == true)
    {
        aTimer.sleep(timems);
        
        // dosiere bis abbruch...Ventil wird geschlossen über Waage->addgewicht->Subjekt->Observer->Update->UpdatevonDosierer->setventilOffen=true)
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
bool Dosierer::isVentilOffen()
{
    return m_bVentilOffen;
}

// Methode der Klasse "Update" wird überschrieben. "Update" wird aufgerufen, wenn UpdateGewicht aufgerufenn wird.
// Eiswurfel und Limettenstücke erhalten zudem noch unter "aktionAusführen" eine gesonderte Abfrage und Dosierparameter
// wennn Maxgewicht erreicht wird, dann wir das Ventil geschlossen
void Dosierer::update()
{
    cout << m_Waage->getDeltaGwicht() << "/" << m_maxMenge << "g" << endl;
    
    if ( m_Waage->getDeltaGwicht() >= m_maxMenge)
    {
         // dann schliesse das Ventil
        setVentilOffen(false);
        cout << "Ventil " << getZutat() << ": geschlossen." << endl;
    }
}

