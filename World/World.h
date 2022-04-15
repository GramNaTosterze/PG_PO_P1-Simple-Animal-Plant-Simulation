#pragma once
#include "Organisms/Organism.h"
#include "Organisms/Animal.h"
#include "Organisms/Plant.h"
#include "Canvas.h"
#include <vector>
using namespace std;
class World {
    private:
    Canvas* canvas;
    vector<Organism*> organisms;
    public:
    World(unsigned int X, unsigned int Y, unsigned int n);
    void addOrganism(Animal* n);
    void addOrganism(Plant* n);
    void makeATurn();
    void drawWorld();
    Canvas* getCanvas();
    void sort(int l ,int r);
    ~World();
};