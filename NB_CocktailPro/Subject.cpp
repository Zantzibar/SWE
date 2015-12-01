#include "Subject.h"

// Registriert einen Observer.
void Subject::attach(
	//Der Observer.
	Observer * observer)
{
	mObservers.push_back(observer);
}

// Meldet einen Observer ab.
void Subject::detach(
	//Der Observer.
	Observer * observer)
{
	mObservers.remove(observer);
}

// Benachrichtigt alle registrierten Observer.
void Subject::notify()
{
	std::list<Observer*>::iterator i;

	for (i = mObservers.begin(); i != mObservers.end(); i++)
	{
		(*i)->update();
	}
}