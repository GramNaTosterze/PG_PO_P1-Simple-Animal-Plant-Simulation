#pragma once
#include "../Animal.h"

class Fox : public Animal {
    public:
    Fox(Pos, Canvas*);
    void move(int, int) override;
};