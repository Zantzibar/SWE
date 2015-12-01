/**
 * @(#) Dosierer.cpp
 */

#include <string>
#include <iostream>
#include "Dosierer.h"

using namespace std;

Dosierer::Dosierer(Waage* waage, std::string zutat) :
	Geraet("Dosieren"),
	mWaage(waage),
	mZutat(zutat),
	mMengenLimit(0),
	isVentilOpen(false)
{
	std::cout << zutat << "-Dosierer initialisiert" << endl;
}


Dosierer::~Dosierer()
{

}

void Dosierer::update()
{
	cout <<
		'\r' << mWaage->getDeltaGewicht() << " / " <<
		mMengenLimit << "g" << flush;

	if (mWaage->getDeltaGewicht() >= mMengenLimit)
		ventilSchliessen();
}

void Dosierer::aktionAusfuehren(float menge)
{
	
}


void Dosierer:: dosieren(float gewicht, int timems)
{
	
}

void Dosierer::setVentilStatus(bool vState)
{
	
}

