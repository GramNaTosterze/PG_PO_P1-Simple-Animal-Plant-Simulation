#pragma once
#include "../Animal.h"

class Turtle : public Animal {
    public:
    Turtle(Pos, Canvas*);
    void addInstanceOf(Pos) override;
    void action() override;
    void colision(Animal*) override;
};