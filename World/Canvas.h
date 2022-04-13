#pragma once
#include "Position.h"
class Canvas {
    private:
    char** board;
    unsigned int X,Y;
    public:
    Canvas(unsigned int X, unsigned int Y);
    unsigned int getX();
    unsigned int getY();
    void set(Pos pos, char s);
    void check_colision();
    void draw();
};