#pragma once

#include "Organism.h"
#include "../Canvas.h"

class Roslina : public Organism {
    private:
    unsigned int sila;
    int inicjatywa;
    Pos polozenie;
    char** swiat;
    char symbol;
    public:
    Roslina(unsigned int sila, int inicjatywa, Pos polozenie, char** plutno, char symbol);
    void akcja();
    void kolizja();
    void rysowanie();

    ~Roslina();
};