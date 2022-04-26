#include "Wolf.h"

Wolf::Wolf(Pos position, Canvas *canvas): Animal(9,5,position,canvas,WOLF){}
string Wolf::getName() const{return "Wilk";}