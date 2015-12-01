#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"
#include <list>

// Repraesentiert das Subject im Beobachtermuster.
class Subject
{

public:
	// Registriert einen Observer.
	virtual void attach(
		//Der Observer.
		Observer * observer);

	// Meldet einen Observer ab.
	virtual void detach(
		//Der Observer.
		Observer * observer);

	// Benachrichtigt alle registrierten Observer.
	virtual void notify();

private:
	// Die Liste der Observer.
	std::list<Observer *> mObservers;


};

#endif