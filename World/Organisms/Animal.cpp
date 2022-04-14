
#include "Animal.h"
#include "../../defines.h"
#include <cstdlib>
#include <time.h>

Animal::Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol) : Organism(strength,initiative,position,canvas,symbol) {}
void Animal::action() {
    //DIRECTIONS direction = DIRECTIONS(rand()%4);
    //switch(direction){
    //    case UP: {
    //        move(0,-1);
    //        return;
    //    }
    //    case DOWN: {
    //        move(0,1);
    //        return;
    //    }
    //    case LEFT: {
    //        move(-1,0);
    //        return;
    //    }
    //    case RIGHT: {
    //        move(1,0);
    //        return;
    //    }
    //}
    world->set(position,this);
}
void Animal::move(int x, int y) {
    world->set(position,(Animal*)nullptr);
    if(position.x+x >= 0 && position.x+x < BOARDX)
        position.x =+ x;
    if(position.y+y >= 0 && position.y+y < BOARDY)
        position.y =+ y;
}
void Animal::colision() {

}
char Animal::draw() {
    return symbol;
}
Animal::~Animal() {}