#pragma once
#include "../Animal.h"

class Sheep : public Animal {
    public:
    Sheep(Pos, Canvas*);
    void addInstanceOf(Pos) override;
};