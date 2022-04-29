
#include "Organism.h"

Organism::Organism(unsigned int strength,unsigned int initiative, Pos position, Canvas* canvas, char symbol, string name, TYPE type): strength(strength),initiative(initiative), position(position), world(canvas), symbol(symbol), age(0), name(name), type(type){}
unsigned int Organism::getStrength() const{return strength;}
unsigned int Organism::getInitiative() const{return initiative;}
unsigned int Organism::getAge() const{return age;}
Pos Organism::getPosition() const{return position;}
string Organism::getName() const{return name;}
TYPE Organism::getType() const{return type;}
bool Organism::operator<(const Organism& other) const{
    return (initiative < other.initiative || (initiative == other.initiative && age < other.age));
}
ostream& operator<<(ostream& out, Organism* organism) {
    out<<organism->symbol<<' '<<organism->position<<' '<<organism->strength<<' '<<organism->initiative<<' '<<organism->age;
    return out;
}
istream& operator>>(istream& in, Organism*& organism) {
    in>> organism->strength>> organism->initiative>> organism->age;
    return in;
}
