#include <iostream>
#include "Human.h"
#include "../../../defines.h"
using namespace std;
Human::Human(Pos position, Canvas *canvas) : Animal(5,4,position,canvas,HUMAN) {}
void Human::action() {
    //world->set(position,this);
    char p;
    cin.clear();
    cin.ignore(10000, '\n');
    cin>>p;
    switch(p) {
        case 'w': {
            move(0,1);
            return;
        }
        case 's': {
            move(0,-1);
            return;
        }
        case 'a': {
            move(-1,0);
            return;
        }
        case 'd': {
            move(1,0);
            return;
        }

    }
}
void Human::colision() {
    
}