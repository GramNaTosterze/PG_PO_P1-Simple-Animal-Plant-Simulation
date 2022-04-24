#pragma once

#include "Organism.h"
#include "Animal.h"

class Plant : public Organism {
    protected:
    unsigned int age;
    public:
    Plant(unsigned int, Pos, Canvas*, char,Info*);
    unsigned int getStrength() const override;
    unsigned int getInitiative() const override;
    unsigned int getAge() const;
    Pos getPosition() const override;
    void setPosition(Pos) override;
    string getName() const override;
    void action() override;
    virtual void spread();
    virtual void addInstanceOf(Pos) = 0;
    void colision(Animal*) override;
    void colision(Plant*) override;
    char draw() override;
    void replace(Organism*,Organism*) override;

    ~Plant();
};