/**
 * @(#) Geraet.h
 */

#ifndef GERAET_H_H
#define GERAET_H_H

#include "stdafx.h"

#include "Stampfer.h"
#include "Mischer.h"
#include "Dosierer.h"

/**
 * Verarbeitet einen Rezeptschritt
 */
class Geraet
{
	
public:

	Geraet();
	~Geraet();

	/**
	 * 
	 */
	void aktionAusfuehren(float menge);
	/**
	 * 
	 */
	
private:
	/**
	 * 
	 */
	Dosierer m_dosierer;
	
	/**
	 * 
	 */
	Mischer m_mischer;
	
	/**
	 * 
	 */
	Stampfer m_stampfer;
	
	
};

#endif
