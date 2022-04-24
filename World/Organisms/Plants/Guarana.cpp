
#include "Guarana.h"

Guarana::Guarana(Pos position, Canvas* canvas,Info* info): Plant(0,position,canvas,GUARANA,info) {}
void Guarana::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Guarana(pos,world,info));
}
void Guarana::colision(Animal* other) {
    other->setStrength(other->getStrength()+3);
    Plant::colision(other);
}