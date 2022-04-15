
#include "Fox.h"

Fox::Fox(Pos position, Canvas *canvas): Animal(3,7,position,canvas,FOX) {}
void Fox::action() {
    Animal::action();
}