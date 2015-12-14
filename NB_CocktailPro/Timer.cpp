/**
 * @(#) Timer.cpp
 */


#include "Timer.h"

#include <ctime>

bool Timer::sb_TurboMode;

Timer::Timer()
{
	
}

void Timer::sleep(int iMS)
{
    // Gerippt von CloneAndOwn.

    static const float multi_10 = 0.1f;

    if (Timer::isTurboModeAktiv())
    {
        iMS = (int)((float)iMS * multi_10);
    }
    
    // clown and own
    clock_t limit;
    clock_t now = clock();

    limit = now + iMS * CLOCKS_PER_SEC / 1000;

    while (limit > now)
    {
        now = clock();
    }
}


bool Timer::isTurboModeAktiv()
{
    return sb_TurboMode;
}

void Timer::setTurboModeAktiv(bool bActive)
{
    sb_TurboMode = bActive;
}

