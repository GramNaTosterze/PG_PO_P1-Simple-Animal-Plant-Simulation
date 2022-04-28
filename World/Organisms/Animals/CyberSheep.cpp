
#include "CyberSheep.h"

CyberSheep::CyberSheep(Pos position, Canvas *canvas): Sheep(position,canvas), destination(EMPTY_POS) {
    strength = 11;
    symbol = CYBER_SHEEP;
    name = "Cyber Owca";
}
void CyberSheep::action() {
    //if(destination == Pos(EMPTY_POS)) {
        //Organism* sos = world->organismsTable().find(HERACLEUM_SOSNOWSKYI);
        //destination = sos->getPosition();
    //}
    
    if(destination == Pos(EMPTY_POS))
        Sheep::action();
    else {
        age++;
        //exterminacja barszczu
    }
}
void CyberSheep::colision(Plant* other) {
    Sheep::colision(other);
}