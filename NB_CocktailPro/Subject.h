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
	void attach(const Observer * obs);
	/**
	 * 
	 */
	void dettach(const Observer * obs);
	/**
	 * 
	 */
	void notify();
	
private:
	/**
	 * 
	 */
	vector<Observer*> m_Obersver;
	
	
};

#endif
