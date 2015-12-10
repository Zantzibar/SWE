/**
 * @(#) RezepturProzessor.cpp
 */


#include "RezepturProzessor.h"
#include "Geraet.h"
#include "Dosierer.h"
#include "Mischer.h"
#include "Stampfer.h"

/**
 * 
 */
RezepturProzessor::RezepturProzessor(Zutatenliste * zutaten)
{
    m_Waage = new Waage();
    m_Mischbehaelter = new Mischbehaelter(m_Waage);

    mapGeraetZutat.insert(pair<string, Geraet*>("Mischen", new Mischer()));

    mapGeraetZutat.insert(pair<string, Geraet*>("Stampfen", new Stampfer()));

    // Fuer jede Zutat einen Dosierer erzeugen.
    for (int i = 0; i < zutaten->getAnzahlZutaten(); i++)
    {
        Dosierer* dosierer = new Dosierer(m_Waage, zutaten->getZutat(i));
        mapGeraetZutat.insert(pair<string, Geraet*>(dosierer->getZutat(), dosierer));
    }
}

/**
 * 
 */
void RezepturProzessor::zubereiten(Rezept* rezept)
{
    cout << rezept->getName() << " wird zubereitet" << endl;

    for (int i = 0; i < rezept->getAnzahlRezeptschritte(); i++)
    {
        Rezeptschritt* schritt = rezept->getRezeptSchritt(i);

        Geraet* einheit = mapGeraetZutat[schritt->getZutat()];
        
        float menge = schritt->getMenge();
        
        if(schritt->getZutat() == "Limettenstuecke")
            menge = menge*10;
                    
	einheit->aktionAusfuehren(menge);
    }

    m_Mischbehaelter->entleeren();
}

