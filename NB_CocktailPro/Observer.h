#ifndef OBSERVER_H_H
#define OBSERVER_H_H

//Abstrakte Observer-Klasse.
class Observer
{

public:
	//Wird vom Subjekt aufgerufen.
	virtual void update() = 0;

};

#endif