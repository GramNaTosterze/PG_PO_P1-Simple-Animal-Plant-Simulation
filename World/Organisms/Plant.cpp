
#include "Plant.h"
#include <iostream>

Plant::Plant(unsigned int strength, Pos position, Canvas* canvas, char symbol): Organism(strength,0,position,canvas,symbol){
    world->set(position,this);
}
unsigned int Plant::getStrength() const {
    return strength;
}
unsigned int Plant::getInitiative() const {
    return initiative;
}
unsigned int Plant::getAge() const {return age;}
void Plant::action() {
    
    spread();
    age++;
}
void Plant::spread() {
    if(age != 0 &&  rand()%3 == 1) {
        Pos pos = world->nextPos(this->position);
            std::cout<<pos.x<<" "<<pos.y<<'\n';
        if(pos.x != -1 && pos.y != -1) {
            if((*world)[pos] == nullptr )
                addInstanceOf(pos);
        }
    }
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