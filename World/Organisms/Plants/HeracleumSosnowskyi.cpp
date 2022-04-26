
#include "HeracleumSosnowskyi.h"

HeracleumSosnowskyi::HeracleumSosnowskyi(Pos position, Canvas* canvas): Plant(10,position,canvas,HERACLEUM_SOSNOWSKYI) {}
void HeracleumSosnowskyi::addInstanceOf(Pos pos) {
    world->organismsTable().add(new HeracleumSosnowskyi(pos,world));
}
void HeracleumSosnowskyi::action() {
    
    Plant::spread();
    age++;
}
void HeracleumSosnowskyi::colision(Animal* other) {
    world->organismsTable().remove(other);
}