/**
 * @(#) RezepturProzessor.h
 */

#ifndef REZEPTURPROZESSOR_H_H
#define REZEPTURPROZESSOR_H_H

#include "Geraet.h"
#include "Mischbehaelter.h"
//#include "Waage.h"
#include "Rezeptbuch.h"

/**
 * Enthält ein Rezept und deligiert die einzelnen Schritte
 */
class RezepturProzessor
{
	
public:
	/**
	 * 
	 */
	RezepturProzessor();
	/**
	 * 
	 */
	void zubereiten();
	
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
