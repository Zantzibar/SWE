/**
 * @(#) Geraet.h
 */

#ifndef GERAET_H_H
#define GERAET_H_H


#include <string>

using namespace std;

/**
 * Verarbeitet einen Rezeptschritt
 */
class Geraet
{
public:
    Geraet();
    // Konstruktor.
    Geraet(string geraetename);

    //Führt die Aktion der Einheit aus.
    virtual void aktionAusfuehren(float menge) = 0;

    //Liefert die Aktion der Einheit zurück.
    string getAktion() const;

private:
    //Der Name der Aktion, die diese Einheit durchführt.
    string mAktion;

};

#endif
