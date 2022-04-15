
#include "Turtle.h"

Turtle::Turtle(Pos position, Canvas *canvas): Animal(2,1,position,canvas,TURTLE) {}
void Turtle::action() {
    //szansa tylko, zmianić składnie poza randem do funkcji
    Animal::action();
}
void Turtle::colision(Animal* other) {
    if(other->getStrength() < 5)
        world->set(other->getPosition(),other);
    else
        Animal::colision(other);
}