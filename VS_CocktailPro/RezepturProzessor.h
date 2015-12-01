/**
 * @(#) RezepturProzessor.h
 */

#ifndef REZEPTURPROZESSOR_H_H
#define REZEPTURPROZESSOR_H_H

#include "Geraet.h"
#include "Mischbehaelter.h"
//#include "Waage.h"
#include "Rezeptbuch.h"
#include "Zutatenliste.h"

/**
 * Enthält ein Rezept und deligiert die einzelnen Schritte
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
	/**
	 * 
	 */
	Geraet * m_Dosierstation;
	
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
