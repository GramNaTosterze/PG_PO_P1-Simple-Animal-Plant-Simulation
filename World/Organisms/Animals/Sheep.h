#pragma once
#include "../Animal.h"

class Sheep : public Animal {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Sheep(Pos position, Canvas *canvas);

    ~Sheep();
};