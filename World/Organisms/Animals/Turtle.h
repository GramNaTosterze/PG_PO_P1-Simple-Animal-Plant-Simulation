#pragma once
#include "Animal.h"

class Turtle : public Animal {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Turtle(Pos position, Canvas *canvas);
    void actions();
    void colision();
    ~Turtle();
};