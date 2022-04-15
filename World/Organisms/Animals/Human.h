#pragma once
#include "../Animal.h"

class Human : public Animal {
    public:
    Human(Pos position, Canvas *canvas);
    void action() override;
    void colision(Animal* other) override;
    void colision(Plant* other) override;

    ~Human();
};