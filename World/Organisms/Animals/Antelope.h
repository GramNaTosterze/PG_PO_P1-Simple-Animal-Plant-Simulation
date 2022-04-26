#pragma once
#include "../Animal.h"

class Antelope : public Animal {
    public:
    Antelope(Pos, Canvas*);
    string getName() const override;
    void action() override;
    void colision(Animal*) override;
};