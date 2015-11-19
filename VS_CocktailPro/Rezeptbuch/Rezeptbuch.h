/**
 * @(#) Rezeptbuch.h
 */

#ifndef REZEPTBUCH_H_H
#define REZEPTBUCH_H_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Jeder Rezeptsschritt hat eine Zutat und eine Menge. Das wird frei interpretiert, d.h. eine Zutat kann auch "Mixen" sein. Die Menge bezieht sich dann auf die Zeit (20 = 20 Sekunden)
 *  
 */
class Rezeptschritt
{
	
public:
	/**
	 * Destruktor 
	 */
	~Rezeptschritt();
	/**
	 * Liefert den Wert des Rezeptschrittes (die Menge) 
	 */
	float getMenge(void) const;
	/**
	 * Liefert die Zutat des Rezeptschrittes 
	 */
	string getZutat(void) const;
	/**
	 * Konstruktor 
	 */
	Rezeptschritt(void);
	/**
	 * Setzt den Wert des Rezeptschrittes (die Menge) 
	 */
	void setMenge(float m_Menge);
	/**
	 * Setzt die Zutat des Rezeptschrittes 
	 */
	void setZutat(std::string m_Zutat);
	
private:
	/**
	 * Die Menge der Zutat - das k?nnen Sekunden, St?ck oder Gramm sein 
	 */
	float m_Menge;
	
	/**
	 * Der Name der Zutat 
	 */
	std::string m_Zutat;
	
	
};
/**
 * Ein Rezept hat einen Namen und verwaltet eine beliebig lange Liste von Rezeptschritten.
 *  
 */
class Rezept
{
	
public:
	/**
	 * Destruktor. L?scht ein Rezept inklusive der enthaltenen Rezeprtschritte. 
	 */
	~Rezept();
	/**
	 * Erzeugt einen neuen Rezeptschritt mit der ?bergebenen Zutat und der Menge und h?ngt den an die Liste der Schritte an.
	 *  
	 */
	void appendStep(std::string z, float m);
	/**
	 * Liefert die Anzahl der Rezeptschritte 
	 */
	int getAnzahlRezeptschritte();
	/**
	 * Liefert den Namen des Rezeptes 
	 */
	std::string getName(void) const;
	/**
	 * Liefert einen Verweis auf den i-ten Rezeptschritt (0..n-1).
	 * Sonst wird eine NULL geliefert.
	 *  
	 */
	Rezeptschritt * getRezeptSchritt(unsigned int i);
	/**
	 * Konstruktor - legt ein Rezept an. 
	 */
	Rezept(void);
	/**
	 * Setzt den Namen des Rezeptes 
	 */
	void setName(std::string Name);
	
private:
	/**
	 * Der Name des Rezeptes 
	 */
	std::string m_Name;
	
	/**
	 * Jedes Rezept besteht aus vielen Rezeptschritten. Die werden hier (geordnet) in einer Liste abgelegt.
	 *  
	 */
	vector<Rezeptschritt> m_Rezeptschritte;
	
	
};
/**
 * Das Rezeptbuch kennt eine Liste von Rezepten. Es bietet die M?glichkeit Rezepte zu suchen und abzufragen. Das Initialisieren der Rezepte erfolgt ?ber den Dateileser.
 *  
 */
class Rezeptbuch
{
	
public:
	/**
	 * Destruktor. L?scht insbesondere den Initialisierer 
	 */
	~Rezeptbuch();
	/**
	 * L?scht das i-te Rezept. Liefert bei Erfolg true, sonst false. 
	 */
	bool deleteRezept(unsigned int i);
	/**
	 * Liefert die Anzahl der verf?gbaren Rezepte. 
	 */
	int getAnzahlRezepte();
	/**
	 * Liefert das i-te Rezept aus der Liste (Werte von 0..n-1).
	 * Ansonsten NULL.
	 *  
	 */
	Rezept * getRezept(unsigned int i);
	/**
	 * Konstruktor; legt tempor?r einen Initialisierer an, damit dieser die Liste auff?llt.
	 *  
	 */
	Rezeptbuch(void);
	
private:
	/**
	 * Ein Rezeptbuch besteht aus vielen Rezepten - diese werden als eine Liste abgelegt.
	 *  
	 */
	vector<Rezept *> m_Rezepte;
	
	
};

#endif
