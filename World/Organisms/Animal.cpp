
#include "Animal.h"
#include "../../defines.h"
#include <cstdlib>
#include <time.h>

Animal::Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol) : Organism(strength,position,canvas,symbol), initiative(initiative), age(0) {
    world->set(position,this);
}
unsigned int Animal::getStrength() const {
    return strength;
}
unsigned int Animal::getInitiative() const {
    return initiative;
}
unsigned int Animal::getAge() const {
    return age;
}
void Animal::action() {
    DIRECTIONS direction = STAY;//DIRECTIONS(rand()%4);
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

//jakiś pomysł był
    position = newPos;
    if((*world)[newPos] == nullptr)
        world->set(position,this);
    else
        (*world)[newPos]->colision(this);
}
void Animal::colision(Animal* other) {
    if(this->strength > other->getStrength()) {
        world->set(position,this);
        world->organismsTable().remove(other);
    }
    else {
        world->set(position,other);
        world->organismsTable().remove(this);
    }
}
void Animal::colision(Plant* other) {

}
char Animal::draw() {
    return symbol;
}
Animal::~Animal() {}