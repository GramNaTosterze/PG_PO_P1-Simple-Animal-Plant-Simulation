#pragma once
#include "../Animal.h"

class Antelope : public Animal {
    public:
    Antelope(Pos, Canvas*);
    void action() override;
    void colision(Animal*) override;
};