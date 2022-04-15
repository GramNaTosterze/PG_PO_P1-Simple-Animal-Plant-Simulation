#pragma once

#include "../Canvas.h"
#include "../Position.h"


class Organism {
    protected:
    unsigned int strength;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Organism();
    Organism(unsigned int strength, Pos position, Canvas* canvas, char symbol);
    virtual unsigned int getStrength() const = 0;
    virtual unsigned int getInitiative() const = 0;
    virtual unsigned int getAge() const = 0;
    virtual void action() = 0;
    virtual void colision(Animal* other) = 0;
    virtual void colision(Plant* other) = 0;
    virtual char draw() = 0;
    ~Organism();
};