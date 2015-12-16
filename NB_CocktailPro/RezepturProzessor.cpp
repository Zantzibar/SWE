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
//Konstruktor füllt Vector<Geraete*> mit 1xMischer, 1xStampfer, x Dosierer mit (x=anzahlZutaten)
RezepturProzessor::RezepturProzessor(Zutatenliste * zutaten)
{   //unsere Waage wird ins Leben gerufen
    m_Waage = new Waage();
    //Unser Mischbehaelter der einen Pointer auf die Waage erhält
    m_Mischbehaelter = new Mischbehaelter(m_Waage);
    //Der Mischer wird erzeugt und dem vector hinzugefügt
    vectorGeraetZutat.push_back(new Mischer("Mischen"));
    //Der Stampfer wird erzeugt und dem vector hinzugefügt
    vectorGeraetZutat.push_back(new Stampfer("Stampfen"));

    // Fuer jede Zutat einen Dosierer erzeugen.
    for (int i = 0; i < zutaten->getAnzahlZutaten(); i++)
    {   //Übergabeparameter für Dosierer sind ein Pointer auf die Waage und den namen der Zutat: string
        Dosierer* dosierer = new Dosierer(m_Waage, zutaten->getZutat(i));
        vectorGeraetZutat.push_back(dosierer);
    }
}
/**
 * 
 */
// Für jeden Rezeptschritt wird das passende geraet anhand des GeraeteNamens gesucht
//Kompletter zubereiteungsvorgang des Rezeptes läuft hier ab
void RezepturProzessor::zubereiten(Rezept* rezept)
{   //Initiale Ausgabe des Rezeptes
    cout << rezept->getName() << " wird zubereitet" << endl;
    
    for (int i = 0; i < rezept->getAnzahlRezeptschritte(); i++)
    {   // Rezeptschritt n von n=0->AnzahlRezeptschritte wird lokal aus Klasse: Rezept übernommen
        Rezeptschritt* schritt = rezept->getRezeptSchritt(i);

        // Abfrage des Geraetenamems (Vergleich von GeraeteName mit RezeptschrittName)
        for (int j = 0;j< vectorGeraetZutat.size();j++)
        {
            //Wenn Bedingung erfülle->Richtiger Dosierer gefunden, dann...
            if(vectorGeraetZutat[j]->getAktion() == rezept->getRezeptSchritt(i)->getZutat() )
            {
                //...wird die zu verarbeitende menge dem speziellen Dosierer übergeben(LimettenStücke werden laut Anforderung gesondert behandelt)
                Geraet* einheit = vectorGeraetZutat[j];
                //cout<< einheit->getAktion()<<endl;
                float menge = schritt->getMenge();
                if(schritt->getZutat() == "Limettenstuecke") {menge = menge*10;}
                //Dosierer/Mischer/Stampfer haben spezielle implementierungen der methode aktionAusfuehren aus Klasse: Geraet
                einheit->aktionAusfuehren(schritt->getMenge());
            }
            else continue;
        }
    }
    //am ende jedes Rezeptes wird der Mischbehaelter entleert
    m_Mischbehaelter->entleeren();
}



