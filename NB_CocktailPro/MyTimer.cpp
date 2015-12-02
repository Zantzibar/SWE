#include "MyTimer.h"
 #include <ctime>

MyTimer::MyTimer()
{
	// Nichts zu tun.
}

void MyTimer::sleep(int timeMs)
{

	clock_t limit;
	clock_t now = clock();

	limit = now + timeMs * CLOCKS_PER_SEC / 1000;

	while (limit > now)
	{
		now = clock();
	}
}

