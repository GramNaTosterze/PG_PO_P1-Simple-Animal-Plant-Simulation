#pragma once

#include "Organism.h"

class Animal : public Organism {
    public:
    Animal(unsigned int, int, Pos, Canvas*, char, string);
    void setPosition(Pos) override;
    void setStrength(unsigned int);
    void action() override;
    virtual void move(int, int);
    void colision(Animal*) override;
    void colision(Plant*) override;
    char draw() override;
    void replace(Organism*,Organism*) override;

    ~Animal();
};