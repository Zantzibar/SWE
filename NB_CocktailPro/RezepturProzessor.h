/**
 * @(#) RezepturProzessor.h
 */

#ifndef REZEPTURPROZESSOR_H_H
#define REZEPTURPROZESSOR_H_H

//#include "Geraet.h"
#include "Mischbehaelter.h"
//#include "Waage.h"
#include "Rezeptbuch.h"
#include "Zutatenliste.h"
#include <map>

using namespace std;

class Geraet;
/**
 * Enth�lt ein Rezept und deligiert die einzelnen Schritte
 */
class RezepturProzessor
{
	
public:

    /**
     * 
     */
    RezepturProzessor(Zutatenliste * zutaten);
    /**
     * 
     */
    void zubereiten(Rezept* rezept);

private:
    RezepturProzessor(){};
    /**
     * 
     */
    Geraet * m_Dosierstation;

    // Mappt Zutaten den entsprechenden Geraeten zu.
    std::map<string, Geraet *> mapGeraetZutat;

    /**
     * 
     */
    Mischbehaelter * m_Mischbehaelter;

    /**
     * 
     */
    Waage * m_Waage;	
};

#endif