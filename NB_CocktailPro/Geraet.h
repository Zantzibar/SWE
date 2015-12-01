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
    Geraet(string bezeichnerFunktion);
    ~Geraet();

    /**
     * 
     */
    void aktionAusfuehren(float menge);
    /**
     * 
     */

private:
};

#endif
