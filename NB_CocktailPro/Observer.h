/**
 * @(#) Observer.h
 */

#ifndef OBSERVER_H_H
#define OBSERVER_H_H

/**
 * 
 */
class Observer
{
	
public:
	/**
	 * 
	 */
         //wird von Klasse: Dosierer überschrieben
	virtual void update() = 0;
	
};

#endif
