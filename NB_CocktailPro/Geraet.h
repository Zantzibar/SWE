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
    Geraet(std::string geraetename);

    //Führt die Aktion der Einheit aus.
    virtual void verarbeiten(float menge) = 0;

    //Liefert die Aktion der Einheit zurück.
    std::string getAktion() const;

private:
    //Der Name der Aktion, die diese Einheit durchführt.
    std::string mAktion;

};

#endif
