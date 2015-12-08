/**
 * @(#) Geraet.cpp
 */


#include "Geraet.h"

Geraet::Geraet()
{
    
}

Geraet::Geraet(std::string aktion)
{
    mAktion = aktion;
}

std::string Geraet::getAktion() const
{
    return mAktion;
}

