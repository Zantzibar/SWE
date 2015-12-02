/**
 * @(#) Dosierer.cpp
 */

#include "Dosierer.h"
#include "MyTimer.h"
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

void Dosierer:: dosieren(float gewichtProStk, int timeMs)
{
	mWaage->attach(this);

	MyTimer timer;

	setVentilStatus(true);

	while (isVentilOpen())
	{
	    // Dosieren... sleep zuerst aufrufen, da dies das Dosieren simuliert.
		timer.sleep(timeMs);

		// Nun Gewicht hinzufügen. Dies sorgt dafür, dass Waage unsere update()
		// Methode aufruft, da wir ein Observer sind.
		mWaage->addGewicht(gewichtProStk);
	}
	mWaage->detach(this);
}

void Dosierer::setVentilStatus(bool bState)
{
    m_bVentilOffen = bState;
}

string Dosierer::getZutat() const
{
	return mZutat;
}