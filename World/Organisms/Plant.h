#pragma once

#include "Organism.h"
#include "Animal.h"

class Plant : public Organism {
    public:
    Plant(unsigned int, Pos, Canvas*, char, string);
    void setPosition(Pos) override;
    void action() override;
    virtual void spread();
    virtual void addInstanceOf(Pos) = 0;
    void colision(Animal*) override;
    void colision(Plant*) override;
    char draw() override;
    void replace(Organism*,Organism*) override;
    ~Plant();
};