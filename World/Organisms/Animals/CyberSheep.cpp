
#include "CyberSheep.h"

CyberSheep::CyberSheep(Pos position, Canvas *canvas): Sheep(position,canvas) {
    setStrength(11);
}
string CyberSheep::getName() const{return "Cyber owca";}
void CyberSheep::action() {
    Sheep::action();
}
void CyberSheep::colision(Plant* other) {
    Sheep::colision(other);
}