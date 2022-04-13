#pragma once
#include "Animal.h"

class Antelope : public Animal {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Antelope(Pos position, Canvas *canvas);
    void action();
    void colision();
    ~Antelope();
};