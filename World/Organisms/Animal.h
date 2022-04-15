#pragma once

#include "Organism.h"

class Animal : public Organism {
    protected:
    unsigned int age;
    public:
    Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol);
    unsigned int getStrength() const override;
    unsigned int getInitiative() const override;
    unsigned int getAge() const;
    Pos getPosition() const;
    void setPosition(Pos pos);
    void action() override;
    virtual void move(int x, int y);
    void colision(Animal* other) override;
    void colision(Plant* other) override;
    char draw() override;

    ~Animal();
};