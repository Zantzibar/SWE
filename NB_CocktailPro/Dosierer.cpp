/**
 * @(#) Dosierer.cpp
 */

#include "Dosierer.h"

#include <iostream>

using namespace std;

Dosierer::Dosierer(Waage* waage, std::string zutat) :
	Geraet("Dosieren"),
	mWaage(waage),
	mZutat(zutat),
	mMengenLimit(0)
{
    setVentilStatus(false);
    std::cout << zutat << "-Dosierer initialisiert" << endl;
}


Dosierer::~Dosierer()
{

}

void Dosierer::update()
{
    cout << '\r' << mWaage->getDeltaGewicht() << " / " << mMengenLimit << "g" << flush;

    if (mWaage->getDeltaGewicht() >= mMengenLimit)
       setVentilStatus(false);
}

void Dosierer::aktionAusfuehren(float menge)
{
	
}


void Dosierer:: dosieren(float gewicht, int timems)
{
	
}

void Dosierer::setVentilStatus(bool bState)
{
    m_bVentil = bState;
}

bool Dosierer::isVentilOpen() 
{ 
    return m_bVentil; 
};

