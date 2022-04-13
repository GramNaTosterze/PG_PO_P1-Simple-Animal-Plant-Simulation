#pragma once

#include "../Animal.h"

class Human : public Animal {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Human(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol);
    void action();
    void colision();
    void draw();

    ~Human();
};