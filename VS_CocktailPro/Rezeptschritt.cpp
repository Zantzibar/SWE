/**
 * @(#) Rezeptschritt.cpp
 */


#include "Rezeptbuch.h"
/**
 * Setzt den Namen des Rezeptes 
 */
void Rezept::setName(std::string Name)
{
	
}

/**
 * Destruktor 
 */
Rezeptschritt::~Rezeptschritt()
{
	
}

/**
 * Konstruktor 
 */
Rezeptschritt::Rezeptschritt(void)
{
	
}

/**
 * Destruktor. L?scht ein Rezept inklusive der enthaltenen Rezeprtschritte. 
 */
Rezept::~Rezept()
{
	
}

/**
 * Erzeugt einen neuen Rezeptschritt mit der ?bergebenen Zutat und der Menge und h?ngt den an die Liste der Schritte an.
 *  
 */
void Rezept::appendStep(std::string z, float m)
{
	
}

/**
 * Liefert das i-te Rezept aus der Liste (Werte von 0..n-1).
 * Ansonsten NULL.
 *  
 */
Rezept * Rezeptbuch::getRezept(unsigned int i)
{
	return 0;
}

/**
 * Destruktor. L?scht insbesondere den Initialisierer 
 */
Rezeptbuch::~Rezeptbuch()
{
	
}

/**
 * Liefert die Zutat des Rezeptschrittes 
 */
std::string Rezeptschritt::getZutat(void) const
{
	return std::string();
}

/**
 * Konstruktor; legt tempor?r einen Initialisierer an, damit dieser die Liste auff?llt.
 *  
 */
Rezeptbuch::Rezeptbuch(void)
{
	
}

/**
 * L?scht das i-te Rezept. Liefert bei Erfolg true, sonst false. 
 */
bool Rezeptbuch::deleteRezept(unsigned int i)
{
	return false;
}

/**
 * Setzt den Wert des Rezeptschrittes (die Menge) 
 */
void Rezeptschritt::setMenge(float m_Menge)
{
	
}

/**
 * Liefert einen Verweis auf den i-ten Rezeptschritt (0..n-1).
 * Sonst wird eine NULL geliefert.
 *  
 */
Rezeptschritt * Rezept::getRezeptSchritt(unsigned int i)
{
	return 0;
}

/**
 * Liefert die Anzahl der Rezeptschritte 
 */
int Rezept::getAnzahlRezeptschritte()
{
	return 0;
}

/**
 * Liefert den Wert des Rezeptschrittes (die Menge) 
 */
float Rezeptschritt::getMenge(void) const
{
	return 0;
}

/**
 * Konstruktor - legt ein Rezept an. 
 */
Rezept::Rezept(void)
{
	
}

/**
 * Setzt die Zutat des Rezeptschrittes 
 */
void Rezeptschritt::setZutat(std::string m_Zutat)
{
	
}

/**
 * Liefert den Namen des Rezeptes 
 */
std::string Rezept::getName(void) const
{
	return std::string();
}

/**
 * Liefert die Anzahl der verf?gbaren Rezepte. 
 */
int Rezeptbuch::getAnzahlRezepte()
{
	return 0;
}

