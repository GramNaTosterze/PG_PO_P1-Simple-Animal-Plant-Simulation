#pragma once

#include "Organism.h"
#include "Plant.h"

class Animal : public Organism {
    protected:
    unsigned int speed;
    public:
    Animal(unsigned int, int, Pos, Canvas*, char, string, unsigned int);
    void setPosition(Pos) override;
    void setStrength(unsigned int);
    void action() override;
    void reproduce();
    virtual void addInstanceOf(Pos) = 0;
    virtual void move(int, int);
    void colision(Animal*) override;
    void colision(Plant*) override;
    char draw() override;
    void replace(Organism*,Organism*) override;
};