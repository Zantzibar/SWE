/**
 * @(#) Subject.h
 */

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"
#include <vector>

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
	vector<Observer*> m_vObservers;
	
	
};

#endif
