
#include "Plant.h"

Plant::Plant(unsigned int strength, Pos position, Canvas* canvas, char symbol, string name): Organism(strength,0,position,canvas,symbol,name,PLANT){
    world->set(position,this);
}
void Plant::setPosition(Pos pos) {this->position = pos;}
void Plant::action() {
    spread();
    age++;
}
void Plant::spread() {
    if(rand()%30 == 1) {
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
    world->addInfoDown(other->getName()+" zjdl rosline "+this->getName());
    world->organismsTable().remove(this);
}
void Plant::colision(Plant* other) {
    world->set(position,this);
    world->organismsTable().remove(other);
}
char Plant::draw() {
    return symbol;
}
void Plant::replace(Organism* one, Organism* two) {

}