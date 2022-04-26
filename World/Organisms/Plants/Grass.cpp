
#include "Grass.h"

Grass::Grass(Pos position, Canvas* canvas): Plant(0,position,canvas,GRASS) {}
void Grass::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Grass(pos,world));
}