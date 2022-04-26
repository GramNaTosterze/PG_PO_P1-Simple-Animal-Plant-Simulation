
#include "Sheep.h"

Sheep::Sheep(Pos position, Canvas *canvas): Animal(4,4,position,canvas,SHEEP){}
string Sheep::getName() const{return "Owca";}