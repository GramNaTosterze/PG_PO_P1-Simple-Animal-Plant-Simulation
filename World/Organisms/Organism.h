#pragma once

#include "../Canvas.h"
#include "../Position.h"


class Organism {
    protected:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Organism();
    Organism(unsigned int strength, int initiative, Pos position, Canvas* canvas, char symbol);
    virtual void action() = 0;
    virtual void colision() = 0;
    virtual char draw() = 0;
    ~Organism();
};