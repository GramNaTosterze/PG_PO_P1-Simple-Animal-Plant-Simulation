
#include "CyberSheep.h"

CyberSheep::CyberSheep(Pos position, Canvas *canvas): Sheep(position,canvas), destination(EMPTY_POS) {
    strength = 11;
    symbol = CYBER_SHEEP;
    name = "Cyber Owca";
}
void CyberSheep::addInstanceOf(Pos pos) {
    world->organismsTable().add(new CyberSheep(pos,world));
}
void CyberSheep::action() {
    if(destination == Pos(EMPTY_POS)) {
        Organism* sos = world->organismsTable().find(SOSNOWSKYS_HOGWEED);
        if(sos != nullptr) {
            world->addInfoDown(name+" wyweszyla "+sos->getName()+"\n");
            destination = sos->getPosition();
        }
    }
    
    if(destination == Pos(EMPTY_POS))
        Sheep::action();
    else {
        age++;
        int x = 0, y = 0;
        if(destination.x > position.x)
            x = 1;
        else if(destination.x < position.x)
            x = -1;
        else if(destination.y < position.y)
            y = -1;
        else if(destination.y > position.y)
            y = 1;
        move(x,y);
    }
}
void CyberSheep::colision(Plant* other) {
    if(other->draw() == SOSNOWSKYS_HOGWEED) {
            world->set(other->getPosition(),nullptr);
            world->addInfoDown(name+" pozbyla sie "+other->getName());
            world->organismsTable().remove(other);
            destination = Pos(EMPTY_POS);
        world->set(position,this);
    }
    else
        Sheep::colision(other);
}