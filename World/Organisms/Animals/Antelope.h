#pragma once
#include "../Animal.h"

class Antelope : public Animal {
    public:
    Antelope(Pos, Canvas*);
    void addInstanceOf(Pos) override;
    void colision(Animal*) override;
};