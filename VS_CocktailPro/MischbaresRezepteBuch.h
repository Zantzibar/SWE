/**
 * @(#)  MischbaresRezepteBuch.h
 */

#ifndef MISCHBARESREZEPTEBUCH_H_H
#define MISCHBARESREZEPTEBUCH_H_H


#include "Rezeptbuch.h"
#include "Zutatenliste.h"
 
 //Ein spezielles Rezeptbuch, das nur mischbare Rezepte enth�lt.
class MischbaresRezeptbuch : public Rezeptbuch
{

public:
	//Konstruktor.
	MischbaresRezeptbuch(Zutatenliste * zutaten);

private:
	//Pr�ft, ob ein Rezept mischbar ist.
	bool istRezeptMischbar(Zutatenliste * zutaten, const Rezept * rezept);

	//Filtert die Rezepte des Buches, je nach Zustand der Cocktail-Maschine.
	void rezepteFiltern(Zutatenliste * zutaten);

};

#endif
