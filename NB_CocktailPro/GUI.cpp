//#include "GUI.h"
//#include "Cocktailmixer.h"
//GUI::GUI(Cocktailmixer* myC)
//{
//
//    this->myCocktailMixer =  myC;
//    showMeAll();
//}

//void GUI::showMeAll()
//{  
//    
//    //myCocktailMixer->attach(this);
//    
//    
//    // notify in den Cocktailmixer...
//    
//    //myCocktailMixer->detach(this);
//     
//}

//void Dosierer::dosieren(float gewicht, int timems)
//{
//    m_Waage->attach(this);
//    
//    Timer aTimer;
//    
//    setVentilOffen(true);
//    cout << "Ventil " << getZutat() << ": geoeffnet." << endl;
//    while(isVentilOffen() == true)
//    {
//        aTimer.sleep(timems);
//        
//        // dosiere bis abbruch...Ventil wird geschlossen über Waage->addgewicht->Subjekt->Observer->Update->UpdatevonDosierer->setventilOffen=true)
//        m_Waage->updategewicht(gewicht);
//    
//    }
//    m_Waage->detach(this);
//}