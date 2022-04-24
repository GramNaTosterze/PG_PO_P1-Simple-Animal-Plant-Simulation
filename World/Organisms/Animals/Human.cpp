#include <iostream>
#include <ncurses.h>
#include "Human.h"

using namespace std;
Human::Human(Pos position, Canvas *canvas, Info* info) : Animal(5,4,position,canvas,HUMAN,info) {
    info->addInfo("Kontrola: strzalki\n");
}
string Human::getName() const{return "Czlowiek";}
void Human::action() {
    info->addInfo("Kontrola: strzałki\n");
    int input = -1;
    while(input != ARROWS) {
        input = getch();
        if(input == ARROWS) {
            getch();
            switch(getch()) {
                case K_UP:{
                    move(-1,0);
                    break;
                }
                case K_DOWN:{
                    move(1,0);
                    break;
                }
                case K_LEFT:{
                    move(0,-1);
                    break;
                }
                case K_RIGHT:{
                    move(0,1);
                    break;
                }
            }
        }
        //refresh();
    }
    
}
void Human::colision(Animal* other) {
    Animal::colision(other);
}
void Human::colision(Plant* other) {
    
}