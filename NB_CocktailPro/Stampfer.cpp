/**
 * @(#) Stampfer.cpp
 */

#include <iostream>
#include "Stampfer.h"
#include "Timer.h"

using namespace std;

Stampfer::Stampfer(){};

void Stampfer::aktionAusfuehren(float menge)
{
    cout<<"Es wird gestampft - Bitte warten"<<endl;
    
    //Da die Zeit in Sekunden angegeben ist, wollen wir die Zeit in Millisekunden umwandeln
    menge *= 1000.0f;
    
    
    // Wir wollen maximal 10 Sterne im Ladebalken haben.
    // Deshalb muessen wir berechnen, wieviel Zeit pro Stern
    // vergehen soll.
    int n = 10;
    int t = (menge / n);

    // Unser Ladebalken-Buffer.
    string Ladebalken = "[          ]";

    // Dient als Indexer fuer Ladebalken.
    int i = 1;
    
    Timer myTimer;
    // Bis wir alle 10 Sterne "geladen" haben.
    while (n > 0)
    {
        // Stern hinzufuegen.
        Ladebalken[i++] = '*';

        // Buffer in gleicher Zeile ausgeben.
        cout << '\r' << Ladebalken << flush;

        // Warten.
        myTimer.sleep(t);

        n--;
    }
}

