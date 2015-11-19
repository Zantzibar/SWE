// main.cpp

#include "..\Cocktailmixer.h"

int main(int argc, char* argv[])
{
    Cocktailmixer* mixer = new Cocktailmixer();
    mixer->Initialisieren(argc, argv);

    delete mixer;

    return 0;
}
