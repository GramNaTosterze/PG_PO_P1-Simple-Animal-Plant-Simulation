#pragma once
#include "../Animal.h"

class CyberSheep : public Animal {
    private:
    unsigned int strength;
    int initiative;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    CyberSheep(Pos position, Canvas *canvas);
    void action() override;
    void colision() override;
    ~CyberSheep();
};