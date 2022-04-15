#pragma once
#include "../Animal.h"

class Fox : public Animal {
    public:
    Fox(Pos position, Canvas *canvas);
    void move(int x, int y) override;
};