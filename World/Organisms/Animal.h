#pragma once

#include "Organism.h"

class Animal : public Organism {
    public:
    Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol);
    void action() override;
    void move(int x, int y);
    void colision() override;
    char draw() override;

    ~Animal();
};