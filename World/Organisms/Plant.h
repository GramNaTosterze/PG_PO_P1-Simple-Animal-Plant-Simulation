#pragma once

#include "Organism.h"

class Plant : public Organism {
    public:
    Plant(unsigned int strength, int initiative, Pos position, Canvas* canvas, char symbol);
    void action() override;
    void colision(Animal* other) override;
    void colision(Plant* other) override;
    char draw() override;

    ~Plant();
};