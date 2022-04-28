
#include "CyberSheep.h"

CyberSheep::CyberSheep(Pos position, Canvas *canvas): Sheep(position,canvas) {
    setStrength(11);
    name = "Cyber Owca";
}
void CyberSheep::action() {
    Sheep::action();
}
void CyberSheep::colision(Plant* other) {
    Sheep::colision(other);
}