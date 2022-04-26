
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Animal.h"
#include "../../defines.h"
using namespace std;

Animal::Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol) : Organism(strength,initiative,position,canvas,symbol), age(0) {
    world->set(position,this);
}
unsigned int Animal::getStrength() const {return strength;}
unsigned int Animal::getInitiative() const {return initiative;}
unsigned int Animal::getAge() const {return age;}
Pos Animal::getPosition() const{return position;}
string Animal::getName() const{return "Zwierze";}
void Animal::setPosition(Pos pos) {
    this->position = pos;
}
void Animal::setStrength(unsigned int strength) {
    this->strength = strength;
}
void Animal::action() {
    DIRECTIONS direction = DIRECTIONS(rand()%4);
    switch(direction){
        case UP: {
            move(0,-1);
            return;
        }
        case DOWN: {
            move(0,1);
            return;
        }
        case LEFT: {
            move(-1,0);
            return;
        }
        case RIGHT: {
            move(1,0);
            return;
        }
    }
}
void Animal::move(int x, int y) {
    world->set(position,(Animal*)nullptr);
    Pos newPos = position;
    if(position.x+x >= 0 && position.x+x < BOARDX)
        newPos.x = position.x + x;
    if(position.y+y >= 0 && position.y+y < BOARDY)
        newPos.y = position.y + y;

    if((*world)[newPos] == nullptr) {
        setPosition(newPos);  
        world->set(newPos,this);
    }
    else
        (*world)[newPos]->colision(this);
}
void Animal::colision(Animal* other) {
    if(this->strength > other->getStrength())
        replace(this,other);
    else
        replace(other,this);
}
void Animal::colision(Plant* other) {

}
char Animal::draw() {
    return symbol;
}
void Animal::replace(Organism* one,Organism* two) {
    world->set(position,one);
    one->setPosition(position);
    string s = one->getName()+" zabija "+two->getName()+"\n";
    world->addInfoDown(s);
    world->organismsTable().remove(two);
}
Animal::~Animal() {}