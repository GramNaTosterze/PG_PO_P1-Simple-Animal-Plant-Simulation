
#include "Sheep.h"

Sheep::Sheep(Pos position, Canvas *canvas, Info* info): Animal(4,4,position,canvas,SHEEP,info){}
string Sheep::getName() const{return "Owca";}