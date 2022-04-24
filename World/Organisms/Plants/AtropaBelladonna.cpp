
#include "AtropaBelladonna.h"

AtropaBelladonna::AtropaBelladonna(Pos position, Canvas* canvas,Info* info): Plant(99,position,canvas,ATROPA_BELLADONNA,info) {}
void AtropaBelladonna::addInstanceOf(Pos pos) {
    world->organismsTable().add(new AtropaBelladonna(pos,world,info));
}
void AtropaBelladonna::colision(Animal* other) {
    world->organismsTable().remove(other);
}