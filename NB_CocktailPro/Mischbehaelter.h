/**
 * @(#) Mischbehaelter.h
 */

#ifndef MISCHBEHAELTER_H_H
#define MISCHBEHAELTER_H_H

#include "Observer.h"
#include "Waage.h"


/**
 * Enthaelt Zutaten und entleert sich.
 */
class Mischbehaelter : public Observer
{
	
public:
    Mischbehaelter(Waage * waage);

    /**
     * 
     */
    void entleeren();

    virtual void update();
    
    void abflussOeffnen(bool bOffen){m_bOffen = bOffen;};
    bool isAbflussOffen(){return m_bOffen;};
	
private:
    /**
     * 
     */
    Waage * m_Waage;
    bool m_bOffen;
    
};

#endif
