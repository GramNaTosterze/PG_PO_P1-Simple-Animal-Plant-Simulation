#pragma once
#include "../Animal.h"

class Wolf : public Animal {
    public:
    Wolf(Pos, Canvas*);
    string getName() const override;
};