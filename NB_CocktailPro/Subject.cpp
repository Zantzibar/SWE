/**
 * @(#) Subject.cpp
 */


#include "Subject.h"

/**
 * 
 */
void Subject::notify()
{
	std::vector<Observer*>::iterator i;

	for (i = m_vObservers.begin(); i != m_vObservers.end(); i++)
	{
		(*i)->update();
	}
}


void Subject::attach(Observer * obs)
{
    m_vObservers.push_back(obs);
}

/**
 * 
 */
void Subject::detach(Observer * obs)
{   
    //m_vObservers.erase(obs); //hier noch vectorspezifisch anpassen
}

