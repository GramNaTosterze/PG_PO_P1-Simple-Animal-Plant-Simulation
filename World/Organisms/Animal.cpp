
#include "Animal.h"

Animal::Animal(unsigned int strength, int initiative, Pos position, Canvas canvas, char symbol) : strength(strength), initiative(initiative), position(position), world(canvas), symbol(symbol){}
void Animal::action() {

}
void Animal::colision() {

}
void Animal::draw() {
    world.set(position,symbol);
}