#pragma once

#include "Organism.h"
#include "../Canvas.h"

class Animal : public Organism {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas** world;
    char symbol;
    public:
    Animal(unsigned int strength, int initiative, Pos position, Canvas canvas, char symbol);
    void action();
    void colision();
    void draw();

    ~Animal();
};