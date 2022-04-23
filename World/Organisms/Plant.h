#pragma once

#include "Organism.h"
#include "Animal.h"

class Plant : public Organism {
    protected:
    unsigned int age;
    public:
    Plant(unsigned int strength, Pos position, Canvas* canvas, char symbol);
    unsigned int getStrength() const override;
    unsigned int getInitiative() const override;
    unsigned int getAge() const;
    void action() override;
    virtual void spread();
    virtual void addInstanceOf(Pos pos) = 0;
    void colision(Animal* other) override;
    void colision(Plant* other) override;
    char draw() override;

    ~Plant();
};