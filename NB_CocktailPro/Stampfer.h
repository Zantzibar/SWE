/**
 * @(#) Stampfer.h
 */

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "Geraet.h"
#include "Timer.h"

/**
 * Stampft x Zeiteinheiten
 */
class Stampfer : public Geraet
{
	
public:
    Stampfer();
    virtual void aktionAusfuehren(float menge);
	
};

#endif
