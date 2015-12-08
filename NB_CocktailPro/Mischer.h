/**
 * @(#) Mischer.h
 */

#ifndef MISCHER_H_H
#define MISCHER_H_H

#include "Geraet.h"

/**
 * Mischt x Zeiteinheiten
 */
class Mischer : public Geraet
{
	
public:
	/**
	 * 
	 */
	virtual void aktionAusfuehren(float menge);
	
};

#endif
