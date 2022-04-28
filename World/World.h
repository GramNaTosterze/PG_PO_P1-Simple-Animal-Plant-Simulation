#pragma once

#include "Organisms/Organism.h"
#include "Organisms/Animal.h"
#include "Organisms/Plant.h"
#include "Canvas.h"
using namespace std;

class World {
    private:
    Canvas* canvas;
    unsigned int currentTurn;
    public:
    World(unsigned int, unsigned int, unsigned int);
    World(unsigned int, unsigned int);
    char randAnimal();
    char randPlant();
    void create(char,Pos);
    void generate();
    template <class Organisms>
    void addOrganism(Pos);
    void turn(bool&);
    Canvas* getCanvas();
    void save(int&);
    void sort(int,int);
    ~World();
};