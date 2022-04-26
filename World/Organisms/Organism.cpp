
#include "Organism.h"

Organism::Organism(): strength(0), position({0,0}), world(nullptr), symbol('_') {}
Organism::Organism(unsigned int strength,unsigned int initiative, Pos position, Canvas* canvas, char symbol): strength(strength),initiative(initiative), position(position), world(canvas), symbol(symbol){}
ostream& operator<<(ostream& out, Organism* organism) {
    out<<organism->draw()<<' '<<organism->getPosition()<<' '<<organism->getStrength()<<' '<<organism->getInitiative()<<' '<<organism->getAge();
    return out;
}
Organism::~Organism() {}
