#pragma once
#include "../Animal.h"

class Fox : public Animal {
    public:
    Fox(Pos, Canvas*, Info*);
    string getName() const override;
    void move(int, int) override;
};