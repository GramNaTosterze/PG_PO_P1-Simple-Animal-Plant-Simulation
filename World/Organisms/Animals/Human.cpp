#include <iostream>
#include "Human.h"
#include "../../../defines.h"
using namespace std;
Human::Human(unsigned int strength, int initiative, Pos position, Canvas *canvas, char symbol) : strength(strength), initiative(initiative), position(position), world(canvas), symbol(symbol) {}
void Human::action() {
    char p;
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
void Human::draw() {
    world->set(position,symbol);
}