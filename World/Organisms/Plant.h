#pragma once

#include "Organism.h"
#include "../Canvas.h"

class Plant : public Organism {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    char** world;
    Canvas* symbol;
    public:
    Plant(unsigned int strength, int initiative, Pos position, Canvas* canvas, char symbol);
    void action() override;
    void colision() override;
    void draw() override;

    ~Plant();
};