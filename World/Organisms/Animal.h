#pragma once

#include "Organism.h"
#include "../Canvas.h"

class Animal : public Organism {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Animal();
    Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol);
    void action() override;
    void move(int x, int y);
    void colision() override;
    void draw() override;

    ~Animal();
};