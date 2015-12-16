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
#include <vector>

using namespace std;
//forward deklaration
class Geraet;
/**
 * Enthaelt ein Rezept und deligiert die einzelnen Schritte
 */
class RezepturProzessor
{
//weiterführende Kommentare in RezepturProzessor.cpp	
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
    
    vector< Geraet * > vectorGeraetZutat;
    
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