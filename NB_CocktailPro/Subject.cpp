/**
 * @(#) Subject.cpp
 */


#include "Subject.h"

/**
 * 
 */

void Subject::notify()
{
    list<Observer*>::iterator i;

    for (i = m_vObservers.begin(); i != m_vObservers.end(); i++)
    {   // alle Observer in der Liste die das Spezifische Subject "observiere" werden aufgefordert sich zu "Update"
        // spezifisch im Fall des Dosierers heisst das, das Ventil zu schliessen
        (*i)->update();
    }
}

//füge einen Observer (Adresse von Dosierer) der Liste hinzu
void Subject::attach(Observer * obs)
{
    m_vObservers.push_back(obs);
}

/**
 * 
 */
//entferne einen Observer (Adresse von Dosierer) aus der Liste
void Subject::detach(Observer * obs)
{   
    m_vObservers.remove(obs);
}

