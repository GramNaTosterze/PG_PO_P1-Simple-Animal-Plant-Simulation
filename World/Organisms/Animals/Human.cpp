#include <iostream>
#include <ncurses.h>
#include "Human.h"

using namespace std;
Human::Human(Pos position, Canvas *canvas) : Animal(5,4,position,canvas,HUMAN,"Czlowiek",1), abilityTimer(0) {}
void Human::control(int& input) {
    input = NEXT_TURN;
    getch();
    direction = getch();
    switch(direction) {
        case K_UP:{
            world->addInfoDown("Kierunek: gora");
            break;
        }
        case K_DOWN:{
            world->addInfoDown("Kierunek: dol");
            break;
        }
        case K_LEFT:{
            world->addInfoDown("Kierunek: lewo");
            break;
        }
        case K_RIGHT:{
            world->addInfoDown("Kierunek: prawo");
            break;
        }
        case K_ABILITY:{
            getch();
            world->addInfoDown("Uzycie calopalenia");
            break;
        }
    }
}
void Human::action() {
    age++;
    printw("%i",direction);
    if(abilityTimer != 0)
        abilityTimer--;
    switch(direction) {
            case K_UP:{
                move(0,-1);
                break;
            }
            case K_DOWN:{
                move(0,1);
                break;
            }
            case K_LEFT:{
                move(-1,0);
                break;
            }
            case K_RIGHT:{
                move(1,0);
                break;
            }
            case K_ABILITY:{
                if(abilityTimer == 0)
                    calopalenie();
                else
                    world->addInfoDown("Calopalenie nie gotowe pozostalo: "+to_string(abilityTimer));      
        }
    }
}
void Human::calopalenie() {
    for(int i = (position.x-1 == -1 ? 0 : position.x-1); i < (position.x+2 == world->getX()? world->getX() : position.x+2); i++)
        for(int j = (position.y-1 == -1 ? 0 : position.y-1); j < (position.y+2 == world->getY()? world->getY() : position.y+2); j++)
            if(position != Pos{i,j} && (*world)[{i,j}] != nullptr) {
                world->addInfoDown("calopalenie dosieglo "+(*world)[{i,j}]->getName());
                world->organismsTable().remove((*world)[{i,j}]);
                world->set({i,j},nullptr);
            }
    abilityTimer = ABILITY_TIMER+1;
}