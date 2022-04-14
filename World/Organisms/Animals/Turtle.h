#pragma once
#include "../Animal.h"

class Turtle : public Animal {
    public:
    Turtle(Pos position, Canvas *canvas);
    void action() override;
    void colision() override;
};