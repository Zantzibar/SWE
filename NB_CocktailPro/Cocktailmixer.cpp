/**
 * @(#) Cocktailmixer.cpp
 */


#include "Cocktailmixer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <stdio_ext.h>

 // Konstruktor. Initialisiert das System beim erzeugen des Objektes
Cocktailmixer::Cocktailmixer()
{   
    Initialisieren();
}

// Destruktor.
Cocktailmixer::~Cocktailmixer()
{
}

// Initialisiert den Cocktail-Mixer.
void Cocktailmixer::Initialisieren()
{   //Neue Zutatenliste wird erzeugt
    mZutaten = new Zutatenliste();
    //Neues Mischbares Rezeptbuch wird erzeugt. Übergabeparameter ist Zutatenliste
    mRezepte = new MischbaresRezepteBuch(mZutaten);

    cout << endl;
    //Neuer RezepturProzessor wird erzeugt. Übergabeparameter ist die Zutatenliste
    mProzessor = new RezepturProzessor(mZutaten);

    cout << endl;
    // vorbereitung für while-Schleife (optional)
    int input = -1;
    
    while (!cin.fail())
    {
        // Anzahl der Rezepte wird lokal aus dem MischbarenRezeptbuch"mRezepte" übernommen
        int anzahlRezepte = mRezepte->getAnzahlRezepte();

        // (Gefilterte) Rezeptliste ausgeben.
        cout << "Es gibt " << anzahlRezepte << " Cocktails" << endl << endl;
        // Mögliche Rezepte werden aus dem MischbarenRezeptbuch auf dem Bildschirm ausgegeben
        for (int i = 0; i < anzahlRezepte; i++)
        {
            Rezept* r = mRezepte->getRezept(i);
            cout << i+1 << ". " << r->getName() << endl;
        }

        cout << endl << "Bitte auswaehlen (0 zum Verlassen): ";
        
        cin >> input;
        //Bei Eingabefehler folgende ausgabe
        if(cin.fail() || input > anzahlRezepte)
        {
            __fpurge(stdin);
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            input = -1;
            cout << "\n\n--------------------------------------------------" << endl;
            cout << "-------------  Ungueltige Eingabe!  --------------" << endl;            
            cout << "--------------------------------------------------\n\n"<< endl;
        }
        //Abbruch bei Eingabe von '0'
        else if (input == 0)
        {
            break;
        }
        //Bei erfolgreicher Eingabe (Ganzzahl zw.1-4)
        else if (input <= anzahlRezepte)
        {
            //Aufruf der Methode "zubereiten" mit einem der Rezepte aus dem MischbarenRezeptbuch
            mProzessor->zubereiten(mRezepte->getRezept(input-1));
        }
    }

    cout << "Bye!" << endl;
}

