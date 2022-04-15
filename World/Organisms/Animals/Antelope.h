#pragma once
#include "../Animal.h"

class Antelope : public Animal {
    public:
    Antelope(Pos position, Canvas *canvas);
    void action() override;
    void colision(Animal* other) override;
};