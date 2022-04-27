
#include <cstdlib>
#include "Antelope.h"

Antelope::Antelope(Pos position, Canvas* canvas): Animal(4,4,position,canvas,ANTELOPE) {}
string Antelope::getName() const{return "Antylopa";}
void Antelope::action() {
    DIRECTIONS direction = DIRECTIONS(rand()%4);
    switch(direction){
        case UP: {
            move(0,-2);
            return;
        }
        case DOWN: {
            move(0,2);
            return;
        }
        case LEFT: {
            move(-2,0);
            return;
        }
        case RIGHT: {
            move(2,0);
            return;
        }
    }
}
void Antelope::colision(Animal* other) {
    if(rand()%2) {
        world->set(world->nextPos(position),this);
        world->addInfoDown(getName()+" uciekla na inne pole");
    }
    else
        Animal::colision(other);
}