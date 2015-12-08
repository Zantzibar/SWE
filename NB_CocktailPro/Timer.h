/**
 * @(#) Timer.h
 */

#ifndef TIMER_H_H
#define TIMER_H_H

/**
 * 
 */
class Timer
{
    
public:
    // Konstruktor.
    Timer();

    void sleep(int iMS);

    static bool isTurboModeAktiv();

    static void setTurboModeAktiv(bool bActive);

private:
    /**
     * turbo modus aktiv?
     */
    static bool sb_TurboMode;

};

#endif
