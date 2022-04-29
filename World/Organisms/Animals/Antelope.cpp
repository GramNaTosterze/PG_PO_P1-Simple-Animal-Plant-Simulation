
#include <cstdlib>
#include "Antelope.h"

Antelope::Antelope(Pos position, Canvas* canvas): Animal(4,4,position,canvas,ANTELOPE,"Antylopa",2) {}
void Antelope::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Antelope(pos,world));
}
void Antelope::colision(Animal* other) {
    if(rand()%2) {
        world->set(position,nullptr);
        world->set(world->nextPos(position),this);
        world->addInfoDown(getName()+" uciekla na inne pole");
    }
    else
        Animal::colision(other);
}