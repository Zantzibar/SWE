/**
 * @(#) Dosierer.cpp
 */


#include "Dosierer.h"
#include "Timer.h"
#include <iostream>

/**
 * 
 */
// Übergabeparameter sind die Waage, die vom Rezepturprozessor erzeugt wird und die zu dosierende Zutat
Dosierer::Dosierer(Waage * waage, string sZutat)
{
    m_maxMenge = 0; // vorlaeufig.. muss menge noch unter aktion ausfuehren bekommen....diese wiederum ruft dosiern auf und setztmax menge = maxMenge
    m_sZutat = sZutat;
    m_Waage = waage;
    mAktion = sZutat; // wird benutzt zur bestimmung des jeweiligen Dosierers im vector<Dosierer* >
    cout << "Dosierer: " << getZutat() << " initialisiert" << endl;
}

/**
 * 
 */
//aktionAusfuehren von Geraet wird überschriebenfür spezifische Anforderung des Dosierer. Analog hierzu sind der Mischer und Stampfer
//Übergabeparameter ist die zu dosierende Menge. (Für Mischer/Stampfer ist es die Zeit)
void Dosierer::aktionAusfuehren(float menge)
{
    m_maxMenge = menge;
    m_Waage->resetDeltaGewicht(); // tara - es wird sichergestellt, dass das Deltagewicht Null ist um Probleme beim Dosiervorgang zu vermeiden
    
    string sZutat = getZutat();
    // intialisieren von gewichtProStck
    float gewichtProStck = 0.0f;
    //Übergabeparameter für die Klasse: Timer
    int timems = 1000; 
    
    if(sZutat == "Limettenstuecke")
    {   //spezifisch für LimettenStücke
        gewichtProStck = 10.0f;
    }
    else if(sZutat == "Eis")
    {   //spezifisch für Eis
        gewichtProStck = 20.0f;        
    }
    else
    {   //Einheitlich für alle weiteren Zutaten (inkl. Zucker)
        gewichtProStck = 1.0f;
        // anpassung der dosiergeschwindigkeit
        timems = 250;
    }
    // Nach bestimmung des Dosiervorgangs wird der eigentliche Dosiervorgang gestartet
    dosieren(gewichtProStck, timems);
}

/**
 * 
 */
// Es wird Dosiert. Abbruch wird über das ObserverMuster angebundene Waage erreicht. (notify() bei Gewichtsänderung der Waage)
void Dosierer::dosieren(float gewicht, int timems)
{   //Die Waage(abgeleitet von Klass: Subject) fügt die Adresse des aufrufenden Dosierers über attach()(abgeleitet von Klass: Observer)
    //der Liste von Observern hinzu.
    m_Waage->attach(this);
    //unser Sleep-Timer wird erzeugt
    Timer aTimer;
    // Ventil wird geoeffnet
    setVentilOffen(true);
    cout << "Ventil " << getZutat() << ": geoeffnet." << endl;
    //Ventil so lange offen bis in der update()-Methode das Ventil geschlossen wird, wenn abbruchbedingung erreicht)
    while(isVentilOffen() == true)
    {   // übergabe der Sleep-Zeit zur simulation des dosiervorgangs
        aTimer.sleep(timems);
        
        // dosiere bis abbruch...Ventil wird geschlossen über Waage->updategewicht()->Subjekt->notify()->Observer->Update()->KonkretesUpdatevonDosierer()->setventilOffen=false
        m_Waage->updategewicht(gewicht);
    
    }
    //Es wird der jeweilige Dosierer wieder aus der Liste entfernt. Hierbei ist das Subject(da Adresse von Waage) die Waage
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
// wennn Maxgewicht erreicht wird, dann wir das Ventil geschlossen
void Dosierer::update()
{   //Ausgabe auf dem Bildschirm vom aktuellen Gewicht und dem Max-Gewicht für abbruch
    cout << m_Waage->getDeltaGwicht() << "/" << m_maxMenge << "g" << endl;
    //wenn Abbruchbedingung erreicht...
    if ( m_Waage->getDeltaGwicht() >= m_maxMenge)
    {
         // ...dann schliesse das Ventil
        setVentilOffen(false);
        cout << "Ventil " << getZutat() << ": geschlossen." << endl;
    }
}

