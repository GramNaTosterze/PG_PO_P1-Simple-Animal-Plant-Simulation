
#include "SosnowskysHogweed.h"
#include "../Animals/CyberSheep.h"

SosnowskysHogweed::SosnowskysHogweed(Pos position, Canvas* canvas): Plant(10,position,canvas,SOSNOWSKYS_HOGWEED,"Barszcz Sosnowskiego") {}
void SosnowskysHogweed::addInstanceOf(Pos pos) {
    world->organismsTable().add(new SosnowskysHogweed(pos,world));
}
void SosnowskysHogweed::action() {
    Organism* tmp;

    for(int i = (position.x-1 == -1 ? 0 : position.x-1); i < (position.x+2 == world->getX()? world->getX() : position.x+2); i++)
        for(int j = (position.y-1 == -1 ? 0 : position.y-1); j < (position.y+2 == world->getY()? world->getY() : position.y+2); j++)
            if(position != Pos{i,j} && (*world)[{i,j}] != nullptr && (*world)[{i,j}]->getType() == ANIMAL) {
                colision(dynamic_cast<Animal*>((*world)[{i,j}]));
                world->set({i,j},nullptr);
            }
    Plant::spread();
    age++;
}
void SosnowskysHogweed::colision(Animal* other) {
    if(other->draw() == CYBER_SHEEP) {
        other->colision(this);
        return;
    }
    world->addInfoDown(other->getName()+" padl ofiara barszczu");
    world->organismsTable().remove(other);
}