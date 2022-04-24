#pragma once
#include "../Animal.h"

class Wolf : public Animal {
    public:
    Wolf(Pos, Canvas*, Info*);
    string getName() const override;
};