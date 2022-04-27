
#include "Fox.h"

Fox::Fox(Pos position, Canvas *canvas): Animal(3,7,position,canvas,FOX) {}
string Fox::getName() const{return "Lisek";}
void Fox::move(int x, int y) {
    world->set(position,(Animal*)nullptr);
    Pos newPos = position;
    if(position.x+x >= 0 && position.x+x < world->getX())
        newPos.x = position.x + x;
    if(position.y+y >= 0 && position.y+y < world->getY())
        newPos.y = position.y + y;

    if((*world)[newPos] == nullptr) {
        setPosition(newPos);  
        world->set(newPos,this);
    }
    else if((*world)[newPos]->getStrength() > strength) {
        world->set(position,this);
        world->addInfoDown(getName()+" postanowil trzymac sie z daleko od pola z drapieznikiem");
    }
    else
        (*world)[newPos]->colision(this);
}