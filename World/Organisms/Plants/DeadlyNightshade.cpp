
#include "DeadlyNightshade.h"

DeadlyNightshade::DeadlyNightshade(Pos position, Canvas* canvas): Plant(99,position,canvas,DEADLY_NIGHTSHADE,"Wilcze jagody") {}
void DeadlyNightshade::addInstanceOf(Pos pos) {
    world->organismsTable().add(new DeadlyNightshade(pos,world));
}
void DeadlyNightshade::colision(Animal* other) {
    world->addInfoDown(getName()+" zaliby stworzenie "+other->getName());
    world->organismsTable().remove(other);
}