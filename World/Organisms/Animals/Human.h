#pragma once
#include "../Animal.h"

class Human : public Animal {
    public:
    Human(Pos, Canvas*, Info*);
    string getName() const override;
    void action() override;
    void colision(Animal*) override;
    void colision(Plant*) override;

    ~Human();
};