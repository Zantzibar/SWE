/**
 * @(#) Mischbehaelter.cpp
 */


#include "Mischbehaelter.h"
#include "Timer.h"
#include <iostream>

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
    cout << "entleere Mischbehaelter" << endl;
    m_Waage->attach(this);

    Timer timer;

    abflussOeffnen(true);

    while (isAbflussOffen())
    {
        // 25g/s
        timer.sleep(1000.0f); // 1s warten
        m_Waage->updategewicht(-25.0f); // abziehen
//optional
//        if(m_Waage->getTotalGewicht()<25.0f)
//        {
//            m_Waage->updategewicht(-(m_Waage->getTotalGewicht()));
//        }
//        else
//        {
//            m_Waage->updategewicht(-25.0f);
//        }
    }

    m_Waage->detach(this);
}

void Mischbehaelter::update()
{
    int iGewGesamt = m_Waage->getTotalGewicht();

    if (iGewGesamt <= 0)
        iGewGesamt = 0;

    cout << iGewGesamt << endl << flush;

    if (iGewGesamt <= 0)
    {
        cout << "Abfluss schließen" << endl;
        abflussOeffnen(false); // schließen        
    }
}