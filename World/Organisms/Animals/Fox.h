#pragma once
#include "Animal.h"

class Fox : public Animal {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Fox(Pos position, Canvas *canvas);
    void action();
    ~Fox();
};