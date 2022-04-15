
#include "Plant.h"

Plant::Plant(unsigned int strength, Pos position, Canvas* canvas, char symbol): Organism(strength,0,position,canvas,symbol){
    world->set(position,this);
}
unsigned int Plant::getStrength() const {
    return strength;
}
unsigned int Plant::getInitiative() const {
    return initiative;
}
unsigned int Plant::getAge() const {return 0;}
void Plant::action() {
    //rozprzestrzenianie się
}
void Plant::colision(Animal* other) {
    world->set(position,other);
    other->setPosition(position);
    world->organismsTable().remove(this);
}
//tmp
void Plant::colision(Plant* other) {
    world->set(position,other);
    //other->setPosition(position);
    world->organismsTable().remove(this);
}
char Plant::draw() {
    return symbol;
}
Plant::~Plant() {

}