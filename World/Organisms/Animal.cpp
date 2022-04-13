
#include "Animal.h"
#include "../../defines.h"
#include <cstdlib>
#include <time.h>

Animal::Animal() : strength(0), initiative(0), position({0,0}), world(nullptr), symbol(' ') {}
Animal::Animal(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol) : strength(strength), initiative(initiative), position(position), world(canvas), symbol(symbol) {}
void Animal::action() {
    DIRECTIONS direction = DIRECTIONS(rand()%4);
    switch(direction){
        case UP: {
            move(-1,0);
            return;
        }
        case DOWN: {
            move(1,0);
            return;
        }
        case LEFT: {
            move(0,-1);
            return;
        }
        case RIGHT: {
            move(0,1);
            return;
        }
    }
}
void Animal::move(int x, int y) {
    position.x =+ x;
    position.y =+ y;
}
void Animal::colision() {

}
void Animal::draw() {
    world->set(position,symbol);
}