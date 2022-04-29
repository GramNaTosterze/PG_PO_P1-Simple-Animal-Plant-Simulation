#pragma once

#include "../Canvas.h"
#include "../Position.h"
#include "../../defines.h"

class Organism {
    protected:
    TYPE type;
    unsigned int strength;
    unsigned int initiative;
    unsigned int age;
    Pos position;
    string name;
    Canvas* world;
    char symbol;
    public:
    Organism(unsigned int,unsigned int, Pos, Canvas*, char,string,TYPE);
    unsigned int getStrength() const;
    unsigned int getInitiative() const;
    unsigned int getAge() const;
    Pos getPosition() const;
    virtual void setPosition(Pos) = 0;
    string getName() const;
    TYPE getType() const;
    virtual void action() = 0;
    virtual void colision(Animal*) = 0;
    virtual void colision(Plant*) = 0;
    virtual char draw() = 0;
    virtual void replace(Organism*,Organism*) = 0;
    bool operator<(const Organism&) const;
    friend ostream& operator<<(ostream&, Organism*);
    friend istream& operator>>(istream&, Organism*&);
};