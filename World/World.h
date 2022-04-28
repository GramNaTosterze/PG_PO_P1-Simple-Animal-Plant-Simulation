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
    World(unsigned int, unsigned int);
    char randOrganism();
    void create(char,Pos);
    void generate();
    template <class Organisms>
    void addOrganism(Pos);
    void turn();
    Canvas* getCanvas();
    void save(int&);
    void sort(int,int);
    ~World();
};