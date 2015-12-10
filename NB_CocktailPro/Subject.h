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
	void attach(Observer * obs);
	/**
	 * 
	 */
	void detach(Observer * obs);
	/**
	 * 
	 */
	void notify();
	
private:
	/**
	 * 
	 */
	list<Observer*> m_vObservers;
	
	
};

#endif
