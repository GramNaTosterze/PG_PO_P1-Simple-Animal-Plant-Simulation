
#include "Plant.h"

Plant::Plant(unsigned int strength, Pos position, Canvas* canvas, char symbol): Organism(strength,0,position,canvas,symbol), age(0){
    world->set(position,this);
}
unsigned int Plant::getStrength() const {return strength;}
unsigned int Plant::getInitiative() const {return initiative;}
unsigned int Plant::getAge() const {return age;}
Pos Plant::getPosition() const {return position;}
void Plant::setPosition(Pos pos) {this->position = pos;}
string Plant::getName() const{return "Roślina";}
void Plant::action() {
    spread();
    age++;
}

void Plant::spread() {
    if(age != 0 &&  rand()%5 == 1) {
        Pos pos = world->nextPos(this->position);
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
void Plant::replace(Organism* one, Organism* two) {

}
Plant::~Plant() {

}