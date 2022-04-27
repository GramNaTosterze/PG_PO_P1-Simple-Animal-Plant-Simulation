#pragma once

#include "../Canvas.h"
#include "../Position.h"
#include "../../defines.h"

class Organism {
    protected:
    unsigned int strength;
    unsigned int initiative;
    unsigned int age;
    Pos position;
    Canvas* world;
    char symbol;
    public:
    Organism(unsigned int,unsigned int, Pos, Canvas*, char);
    virtual unsigned int getStrength() const = 0;
    virtual unsigned int getInitiative() const = 0;
    virtual unsigned int getAge() const = 0;
    virtual Pos getPosition() const = 0;
    virtual void setPosition(Pos) = 0;
    virtual string getName() const = 0;
    virtual void action() = 0;
    virtual void colision(Animal*) = 0;
    virtual void colision(Plant*) = 0;
    virtual char draw() = 0;
    virtual void replace(Organism*,Organism*) = 0;
    friend ostream& operator<<(ostream&, Organism*);
    friend istream& operator>>(istream&, Organism*&);
    ~Organism();
};