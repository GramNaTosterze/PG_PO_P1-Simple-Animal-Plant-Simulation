#pragma once
#include <string>
#include "Position.h"
#include "OrganismTable.h"

using namespace std;

class Organism;
class Animal;
class Plant;

class Canvas {
    private:
    string infoUp;
    string infoDown;
    Organism*** board;
    OrganismTable organisms;
    unsigned int X,Y;
    public:
    Canvas(unsigned int X, unsigned int Y);
    void addInfoUp(string);
    void addInfoDown(string);
    void cleanInfo();
    OrganismTable& organismsTable();
    Organism* operator[] (unsigned int i);
    Organism* operator[] (Pos pos);
    Pos nextPos(Pos pos);
    unsigned int getX();
    unsigned int getY();
    void set(Pos pos, Organism* organism);
    void draw();
};