/**
 * @(#) Subject.h
 */

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"
#include <list>

using namespace std;

/**
 * 
 */
class Subject
{
	
public:
	/**
	 * 
	 */
        //fügt einen Observer der Liste m_vObservers hinzu
	void attach(Observer * obs);
	/**
	 * 
	 */
        //entfernt einen Observer aus der Liste m_vObserver
	void detach(Observer * obs);
	/**
	 * 
	 */
        //benachrichtigt alle Observer ind er Liste m_vObserver, dass diese auf Änderungen prüfen sollen
	void notify();
	
private:
	/**
	 * 
	 */
        //ennthaelt alle Observer der Konkreten Abgeleitete Klasse in unserem UseCase des Cocktailmixers
	list<Observer*> m_vObservers;
	
	
};

#endif
