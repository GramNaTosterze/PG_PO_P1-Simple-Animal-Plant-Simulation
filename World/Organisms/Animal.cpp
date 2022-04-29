
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Animal.h"
#include "../../defines.h"
using namespace std;

Animal::Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol, string name, unsigned int speed) : Organism(strength,initiative,position,canvas,symbol,name,ANIMAL), speed(speed) {
    world->set(position,this);
}
void Animal::setPosition(Pos pos) {
    this->position = pos;
}
void Animal::setStrength(unsigned int strength) {
    this->strength = strength;
}
void Animal::action() {
    age++;
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
void Animal::reproduce() {
    if(age > 0 && rand()%3 == 1) {
        Pos pos = world->nextPos(this->position);
        if(pos.x != -1 && pos.y != -1) {
            if((*world)[pos] == nullptr )
                addInstanceOf(pos);
            world->addInfoDown(name+" rozmnozyl sie");
        }
    }

}
void Animal::move(int x, int y) {
    world->set(position,(Animal*)nullptr);
    Pos newPos = position;
    x = x*speed;
    y = y*speed;
    if(position.x+x >= 0 && position.x+x < world->getX())
        newPos.x = position.x + x;
    if(position.y+y >= 0 && position.y+y < world->getY())
        newPos.y = position.y + y;

    if((*world)[newPos] == nullptr) {
        setPosition(newPos);  
        world->set(newPos,this);
    }
    else
        (*world)[newPos]->colision(this);
}
void Animal::colision(Animal* other) {
    if(symbol == other->draw())
        reproduce();
    else if(this->strength >= other->getStrength())
        replace(this,other);
    else
        replace(other,this);
}
void Animal::colision(Plant* other) {
    replace(this,other);
}
char Animal::draw() {
    return symbol;
}
void Animal::replace(Organism* one,Organism* two) {
    world->set(position,one);
    one->setPosition(position);
    world->addInfoDown(one->getName()+" zabija stworzenie "+two->getName());
    world->organismsTable().remove(two);
}