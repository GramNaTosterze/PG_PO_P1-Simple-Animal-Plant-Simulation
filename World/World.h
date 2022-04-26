#pragma once

#include "Organisms/Organism.h"
#include "Organisms/Animal.h"
#include "Organisms/Plant.h"
#include "Canvas.h"
using namespace std;
class World {
    private:
    Canvas* canvas;
    public:
    World(unsigned int, unsigned int, unsigned int);
    void addOrganism(Organism*);
    void makeATurn();
    void drawWorld();
    Canvas* getCanvas();
    void save();
    void load();
    void sort(int,int);
    ~World();
};