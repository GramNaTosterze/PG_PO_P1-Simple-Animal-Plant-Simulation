#pragma once

#include "Position.h"

class Organism;
class Animal;
class Plant;

class Canvas {
    private:
    Organism*** board;
    unsigned int X,Y;
    public:
    Canvas(unsigned int X, unsigned int Y);
    unsigned int getX();
    unsigned int getY();
    void set(Pos pos, Animal* organism);
    void set(Pos pos, Plant* organism);
    void check_colision();
    void draw();
};