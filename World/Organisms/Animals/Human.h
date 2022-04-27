#pragma once
#include "../Animal.h"

class Human : public Animal {
    private:
    bool madeMove;
    int direction;
    int abilityTimer;
    public:
    Human(Pos, Canvas*);
    string getName() const override;
    void control(int&);
    void action() override;
    void calopalenie();

    ~Human();
};