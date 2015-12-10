/**
 * @(#)  MischbaresRezepteBuch.h
 */

#ifndef MISCHBARESREZEPTEBUCH_H_H
#define MISCHBARESREZEPTEBUCH_H_H


#include "Rezeptbuch.h"
#include "Zutatenliste.h"
  
 //Ein spezielles Rezeptbuch, das nur mischbare Rezepte enth�lt. jhjh
class MischbaresRezepteBuch : public Rezeptbuch
{

public:
	//Konstruktor.
	MischbaresRezepteBuch(Zutatenliste * zutaten);

private:
};

#endif
