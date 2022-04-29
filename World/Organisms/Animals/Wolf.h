#pragma once
#include "../Animal.h"

class Wolf : public Animal {
    public:
    Wolf(Pos, Canvas*);
    void addInstanceOf(Pos) override;
};