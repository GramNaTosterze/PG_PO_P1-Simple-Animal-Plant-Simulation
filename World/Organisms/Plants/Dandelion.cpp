
#include "Dandelion.h"

Dandelion::Dandelion(Pos position, Canvas* canvas,Info* info): Plant(0,position,canvas,DANDELION,info) {}
void Dandelion::action() {
    for(int i = 0; i < 3; i++)
        Plant::spread();
    age++;
}
void Dandelion::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Dandelion(pos,world,info));
}