/**
 * @(#) Mischbehaelter.cpp
 */


#include "Mischbehaelter.h"
#include "Timer.h"

using namespace std;

//Konstruktor.
Mischbehaelter::Mischbehaelter(Waage* pWaage)
{
    m_Waage = pWaage;
}

/**
 * 
 */
void Mischbehaelter::entleeren()
{
    m_Waage->attach(this);

    Timer timer;

    abflussOeffnen(true);

    while (isAbflussOffen())
    {
        // 25g/s
        timer.sleep(1000.0f); // 1s warten
        m_Waage->updategewicht(-25.0f); // abziehen
    }

    m_Waage->detach(this);
}

void Mischbehaelter::update()
{
    
}