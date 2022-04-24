#pragma once
#include "../Animal.h"

class Sheep : public Animal {
    public:
    Sheep(Pos, Canvas*, Info*);
    string getName() const override;
};