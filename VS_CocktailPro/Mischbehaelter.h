/**
 * @(#) Mischbehaelter.h
 */

#ifndef MISCHBEHAELTER_H_H
#define MISCHBEHAELTER_H_H

#include "Waage.h"
/**
 * Enth�lt Zutaten und entleert sich.
 */
class Mischbehaelter
{
	
public:
	/**
	 * 
	 */
	void entleeren();
	
private:
	/**
	 * 
	 */
	Waage * g_Waage;
	
	
};

#endif
