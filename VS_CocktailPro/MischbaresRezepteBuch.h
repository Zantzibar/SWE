/**
 * @(#)  MischbaresRezepteBuch.h
 */

#ifndef MISCHBARESREZEPTEBUCH_H_H
#define MISCHBARESREZEPTEBUCH_H_H


#include "Rezeptbuch.h"
#include "Zutatenliste.h"
 
 //Ein spezielles Rezeptbuch, das nur mischbare Rezepte enthält.
class MischbaresRezepteBuch : public Rezeptbuch
{

public:
	//Konstruktor.
	MischbaresRezepteBuch(Zutatenliste * zutaten);

private:
	//Prüft, ob ein Rezept mischbar ist.
	bool istRezeptMischbar(Zutatenliste * zutaten, const Rezept * rezept);

	//Filtert die Rezepte des Buches, je nach Zustand der Cocktail-Maschine.
	void rezepteFiltern(Zutatenliste * zutaten);

};

#endif
