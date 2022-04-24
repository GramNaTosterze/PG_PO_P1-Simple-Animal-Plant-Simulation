
#include "HeracleumSosnowskyi.h"

HeracleumSosnowskyi::HeracleumSosnowskyi(Pos position, Canvas* canvas, Info* info): Plant(10,position,canvas,HERACLEUM_SOSNOWSKYI,info) {}
void HeracleumSosnowskyi::addInstanceOf(Pos pos) {
    world->organismsTable().add(new HeracleumSosnowskyi(pos,world,info));
}
void HeracleumSosnowskyi::action() {
    
    Plant::spread();
    age++;
}
void HeracleumSosnowskyi::colision(Animal* other) {
    world->organismsTable().remove(other);
}