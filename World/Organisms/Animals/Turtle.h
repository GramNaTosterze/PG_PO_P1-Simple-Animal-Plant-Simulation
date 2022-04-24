#pragma once
#include "../Animal.h"

class Turtle : public Animal {
    public:
    Turtle(Pos, Canvas *, Info*);
    string getName() const override;
    void action() override;
    void colision(Animal*) override;
};