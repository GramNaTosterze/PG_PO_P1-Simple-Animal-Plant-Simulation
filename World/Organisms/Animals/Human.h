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
    Human(Pos position, Canvas *canvas);
    void action() override;
    void colision() override;

    ~Human();
};