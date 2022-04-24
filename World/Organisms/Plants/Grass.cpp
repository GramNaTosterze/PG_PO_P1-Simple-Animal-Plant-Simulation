
#include "Grass.h"

Grass::Grass(Pos position, Canvas* canvas,Info* info): Plant(0,position,canvas,GRASS,info) {}
void Grass::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Grass(pos,world,info));
}