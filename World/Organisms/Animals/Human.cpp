#include <iostream>
#include "Human.h"
#include "../../../defines.h"
using namespace std;
Human::Human(Pos position, Canvas *canvas) : strength(5), initiative(4), position(position), world(canvas), symbol(CZLOWIEK) {}
void Human::action() {
    char p;
    cin.clear();
    cin.ignore(10000, '\n');
    cin>>p;
    switch(p) {
        case 'w': {
            if(position.y > 0)
                position.y--;
            return;
        }
        case 's': {
            if(position.y > BOARDY)
                position.y++;
            return;
        }
        case 'a': {
            if(position.x > 0)
                position.x--;
            return;
        }
        case 'd': {
            if(position.x > BOARDX)
                position.x++;
            return;
        }

    }
}
void Human::colision() {
    
}