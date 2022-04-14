#pragma once
#include "../Animal.h"

class Fox : public Animal {
    public:
    Fox(Pos position, Canvas *canvas);
    void action() override;
};