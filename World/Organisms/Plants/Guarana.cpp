
#include "Guarana.h"

Guarana::Guarana(Pos position, Canvas* canvas): Plant(0,position,canvas,GUARANA) {}
void Guarana::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Guarana(pos,world));
}
void Guarana::colision(Animal* other) {
    other->setStrength(other->getStrength()+3);
    Plant::colision(other);
}