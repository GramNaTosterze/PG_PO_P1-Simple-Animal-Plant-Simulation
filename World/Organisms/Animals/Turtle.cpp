
#include <cstdlib>
#include "Turtle.h"
Turtle::Turtle(Pos position, Canvas *canvas): Animal(2,1,position,canvas,TURTLE,"Zolw",1) {}
void Turtle::action() {
    age++;
    if(rand()%4 == 3) {
        age--;
        Animal::action();
    }
}
void Turtle::colision(Animal* other) {
    if(other->getStrength() < 5) {
        world->set(other->getPosition(),other);
        world->addInfoDown(getName()+" obronil sie przed atakiem stworzenia "+other->getName());
    }
    else
        Animal::colision(other);
}