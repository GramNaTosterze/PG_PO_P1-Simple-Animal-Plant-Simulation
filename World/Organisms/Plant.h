#pragma once

#include "Organism.h"

class Plant : public Organism {
    public:
    Plant(unsigned int strength, int initiative, Pos position, Canvas* canvas, char symbol);
    void action() override;
    void colision() override;
    char draw() override;

    ~Plant();
};