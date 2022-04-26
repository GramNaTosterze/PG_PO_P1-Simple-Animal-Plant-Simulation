
#include "Organism.h"

Organism::Organism(unsigned int strength,unsigned int initiative, Pos position, Canvas* canvas, char symbol): strength(strength),initiative(initiative), position(position), world(canvas), symbol(symbol){}
ostream& operator<<(ostream& out, Organism* organism) {
    out<<organism->draw()<<' '<<organism->getPosition()<<' '<<organism->getStrength()<<' '<<organism->getInitiative()<<' '<<organism->getAge();
    return out;
}
istream& operator>>(istream& in, Organism* organism) {
    in>>organism->symbol>>organism->position>>organism->strength>>organism->initiative>>organism->age;
    return in;
}
Organism::~Organism() {}
