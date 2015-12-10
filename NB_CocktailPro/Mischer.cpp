/**
 * @(#) Mischer.cpp
 */


#include "Mischer.h"
#include "Timer.h"
#include <iostream>


/**
 * 
 */
void Mischer::aktionAusfuehren(float menge)
{
    cout<<"Es wird gemischt - Bitte warten"<<endl;
    
    Timer timer;

    // in sekunden umwandeln
    menge *= 1000.0f;

    // max 10 Sterne
    // Zeit pro Stern berechnen...
    int n = 10;
    int t = (menge / n);

    // Unser Ladebalken-Buffer.
    string s = "[          ]";

    // Dient als Indexer fuer Ladebalken.
    int i = 1;

    // Bis wir alle 10 Sterne "geladen" haben.
    while (n > 0)
    {
        // Stern hinzufuegen.
        s[i++] = '*';

        // Buffer in gleicher Zeile ausgeben.
        cout << '\r' << s << flush;

        // Warten.
        timer.sleep(t);

        n--;
    }

    cout << endl << "OK!\n\n";
}

