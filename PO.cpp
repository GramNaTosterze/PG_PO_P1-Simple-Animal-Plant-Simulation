#include <iostream>
#include <ncurses.h>
#include "World/Session.h"
#include "World/World.h"
#include "World/Organisms/Organism.h"
#include "World/Organisms/Plant.h"
#include "World/Organisms/Animal.h"

#include "World/Organisms/Organisms.h"
#include "defines.h"

using namespace std;

int main () {
    srand(time(NULL));
    Session session;
    int x,y;

    initscr();
    while(session.sessionRunning()) {
        clear();
        printw("l - wczytaj, n - nowa, Esc - zakoncz\n");
        switch(getch()) {
            case LOAD:{
                int input = -1;
                while(input < 1 || input > 3) {
                    clear();
                    printw("slot(1-3)");
                    refresh();
                    input = getch() - '0';
                    printw("\n");
                }
                session.loadWorld(input);
                break;
            } 
            case NEW:{
                printw("rozmiary swiata: ");
                refresh();
                scanw("%i %i",&x,&y);
                session.newWorld(x,y,1);
                session.rand();
                break;
            }
            case ESC:{
                session.end();
            }
        }
        while(session.worldCreated())
            session.manage();
    }
    endwin();
    return 0;
}