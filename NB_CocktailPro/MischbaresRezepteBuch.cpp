/**
 * @(#)  MischbaresRezepteBuch.cpp
 */


#include "MischbaresRezepteBuch.h"

/**
 * 
 */
MischbaresRezepteBuch::MischbaresRezepteBuch(Zutatenliste * zutaten)
{
    //@todo mZutaten von datei fuellen und mischbare rezepte ins rezeptbuch uebertragen
    cout << getAnzahlRezepte() << " Rezepte filtern..." << endl;

    for (int i = 0; i < getAnzahlRezepte(); i++)
    {
        Rezept* rezept = getRezept(i);

        for (int j = 0; j < rezept->getAnzahlRezeptschritte(); j++)
        {
            Rezeptschritt* schritt = rezept->getRezeptSchritt(j);

            string schrittZutat = schritt->getZutat();

            // Ist das Rezept mischbar?
            // "Mischen" und "Stampfen" wird ignoriert.
            if (schrittZutat != "Mischen" &&
                schrittZutat != "Stampfen" &&
                !zutaten->hatZutat(schrittZutat))
            {
                // Rezept löschen.
                cout << "Lösche Rezept \"" << rezept->getName() << "\" weil Zutat " <<
                    schritt->getZutat() << " fehlt!" << endl;

                deleteRezept(i);
                i--;
                break;
            }

        }

    }

}

/**
 * 
 */
void MischbaresRezepteBuch::rezepteFiltern(Zutatenliste * zutaten)
{
	
}

/**
 * 
 */
bool MischbaresRezepteBuch::istRezeptMischbar(Zutatenliste * zutaten, const Rezept * rezept)
{
	return true;
}

