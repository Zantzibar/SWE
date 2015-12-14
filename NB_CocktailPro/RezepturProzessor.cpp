/**
 * @(#) RezepturProzessor.cpp
 */


#include "RezepturProzessor.h"
#include "Geraet.h"
#include "Dosierer.h"
#include "Mischer.h"
#include "Stampfer.h"
#include <vector>

using namespace std;
/**
 * 
 */

RezepturProzessor::RezepturProzessor(Zutatenliste * zutaten)
{
    m_Waage = new Waage();
    m_Mischbehaelter = new Mischbehaelter(m_Waage);

    vectorGeraetZutat.push_back(new Mischer("Mischen"));

    vectorGeraetZutat.push_back(new Stampfer("Stampfen"));

    // Fuer jede Zutat einen Dosierer erzeugen.
    for (int i = 0; i < zutaten->getAnzahlZutaten(); i++)
    {
        Dosierer* dosierer = new Dosierer(m_Waage, zutaten->getZutat(i));
        vectorGeraetZutat.push_back(dosierer);
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

        
        for (int j = 0;j< vectorGeraetZutat.size();j++)
        {
            
            if(vectorGeraetZutat[j]->getAktion() == rezept->getRezeptSchritt(i)->getZutat() )
            {
                
                Geraet* einheit = vectorGeraetZutat[j];
                //cout<< einheit->getAktion()<<endl;
                float menge = schritt->getMenge();
                if(schritt->getZutat() == "Limettenstuecke") {menge = menge*10;}
                einheit->aktionAusfuehren(schritt->getMenge());
            }
            else continue;
        }
    }

    m_Mischbehaelter->entleeren();
}



