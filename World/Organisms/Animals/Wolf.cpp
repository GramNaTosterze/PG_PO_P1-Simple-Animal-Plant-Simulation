#include "Wolf.h"

Wolf::Wolf(Pos position, Canvas *canvas): Animal(9,5,position,canvas,WOLF,"Wilk",1){}
void Wolf::addInstanceOf(Pos pos) {
    world->organismsTable().add(new Wolf(pos,world));
}