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
//RezepturProzessor::RezepturProzessor(Zutatenliste * zutaten)
//{
//    m_Waage = new Waage();
//    m_Mischbehaelter = new Mischbehaelter(m_Waage);
//
//    mapGeraetZutat.insert(pair<string, Geraet*>("Mischen", new Mischer()));
//
//    mapGeraetZutat.insert(pair<string, Geraet*>("Stampfen", new Stampfer()));
//
//    // Fuer jede Zutat einen Dosierer erzeugen.
//    for (int i = 0; i < zutaten->getAnzahlZutaten(); i++)
//    {
//        Dosierer* dosierer = new Dosierer(m_Waage, zutaten->getZutat(i));
//        mapGeraetZutat.insert(pair<string, Geraet*>(dosierer->getZutat(), dosierer));
//    }
//}

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
// Das bleibt, da die Rezeptschritte fest sind
    for (int i = 0; i < rezept->getAnzahlRezeptschritte(); i++)
    {
        Rezeptschritt* schritt = rezept->getRezeptSchritt(i);
// Map adressierung der Einheit über den Namen der map...jetzt über den namen im gerät..es muss aber ver vector durchsucht werden
        //Geraet* einheit = NULL;
        
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
        //float menge = schritt->getMenge();
        // hier muss jetzt über den geraetenamen gegangen werden
        //if(schritt->getZutat() == "Limettenstuecke")
            //menge = menge*10;
                  
	//einheit->aktionAusfuehren(menge); // segmentation fault?
    }

    m_Mischbehaelter->entleeren();
}

//void RezepturProzessor::zubereiten(Rezept* rezept)
//{
//    cout << rezept->getName() << " wird zubereitet" << endl;
//
//    for (int i = 0; i < rezept->getAnzahlRezeptschritte(); i++)
//    {
//        Rezeptschritt* schritt = rezept->getRezeptSchritt(i);
//
//        Geraet* einheit = mapGeraetZutat[schritt->getZutat()];
//        
//        float menge = schritt->getMenge();
//        
//        if(schritt->getZutat() == "Limettenstuecke")
//            menge = menge*10;
//                    
//	einheit->aktionAusfuehren(menge);
//    }
//
//    m_Mischbehaelter->entleeren();
//}

