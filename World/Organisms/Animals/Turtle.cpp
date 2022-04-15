
#include "Turtle.h"

Turtle::Turtle(Pos position, Canvas *canvas): Animal(2,1,position,canvas,TURTLE) {}
void Turtle::action() {

}
void Turtle::colision(Animal* other) {
    if(other->getStrength() < 5)
        return;
    else
        Animal::colision(other);
}