/**
 * @(#) Subject.h
 */

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "list<Observer"$ *", >.h"
#include "Observer.h"
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
	list<Observer"$ *", > m_Obersver;
	
	
};

#endif
