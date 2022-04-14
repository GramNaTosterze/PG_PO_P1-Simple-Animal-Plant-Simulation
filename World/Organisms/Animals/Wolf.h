#pragma once
#include "../Animal.h"

class Wolf : public Animal {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Wolf(Pos position, Canvas *canvas);

    ~Wolf();
};