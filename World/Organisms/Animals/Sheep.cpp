
#include "Sheep.h"

Sheep::Sheep(Pos position, Canvas *canvas): Animal(4,4,position,canvas,SHEEP,"Owca",1){}
void Sheep::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Sheep(pos,world));
}