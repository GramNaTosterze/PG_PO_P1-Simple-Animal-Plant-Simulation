
#include "AtropaBelladonna.h"

AtropaBelladonna::AtropaBelladonna(Pos position, Canvas* canvas): Plant(99,position,canvas,ATROPA_BELLADONNA,"Wilcze jagody") {}
void AtropaBelladonna::addInstanceOf(Pos pos) {
    world->organismsTable().add(new AtropaBelladonna(pos,world));
}
void AtropaBelladonna::colision(Animal* other) {
    world->addInfoDown(getName()+" zaliby stworzenie "+other->getName());
    world->organismsTable().remove(other);
}