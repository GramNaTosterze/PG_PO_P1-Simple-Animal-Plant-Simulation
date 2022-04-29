#pragma once
#include "../Animal.h"

class Fox : public Animal {
    public:
    Fox(Pos, Canvas*);
    void addInstanceOf(Pos) override;
    void move(int, int) override;
};