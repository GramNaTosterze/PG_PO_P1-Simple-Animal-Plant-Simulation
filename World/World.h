#pragma once
#include "Organisms/Organism.h"
#include "Canvas.h"
class World {
    private:
    Canvas canvas;
    Organism* organisms;
    public:
    World(unsigned int X, unsigned int Y, unsigned int n);
    void makeATurn();
    void drawWorld();
    ~World();
};