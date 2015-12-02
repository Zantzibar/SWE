/* 
 * File:   Timer.h
 * Author: debian
 *
 * Created on 2. Dezember 2015, 17:43
 */

#ifndef TIMER_H
#define	TIMER_H

//Steuert das Timing aller Komponenten.
class MyTimer
{
public:
	// Konstruktor.
	MyTimer();
	// Pausiert den Haupt-Thread für eine bestimmte Zeit.
	void sleep(int timeMs);
private:
};

#endif	/* TIMER_H */

