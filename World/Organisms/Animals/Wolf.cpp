#include "Wolf.h"

Wolf::Wolf(Pos position, Canvas *canvas, Info* info): Animal(9,5,position,canvas,WOLF,info){}
string Wolf::getName() const{return "Wilk";}