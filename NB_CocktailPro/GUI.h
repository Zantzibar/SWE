/* 
 * File:   GUI.h
 * Author: debian
 *
 * Created on 14. Dezember 2015, 13:35
 */
#include "Observer.h"
#include "Cocktailmixer.h"

#ifndef GUI_H
#define	GUI_H

// DIE GUI ist der Observer... alles was im Cocktailmixer passiert soll geupdated werden
//attchted sic zum cockteilmixer und reuft die updatefunktion des mixers auf
class GUI //: public Observer
{
public:
    GUI(Cocktailmixer* myC);
    void showMeAll();
    
private:
   
    Cocktailmixer * myCocktailMixer;
}

#endif	/* GUI_H */

