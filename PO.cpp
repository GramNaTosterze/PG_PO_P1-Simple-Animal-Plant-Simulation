#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "World/World.h"
#include "World/Organisms/Organism.h"
#include "World/Organisms/Plant.h"
#include "World/Organisms/Animal.h"

#include "World/Organisms/Organisms.h"
#include "defines.h"

using namespace std;
class Session{
    private:
    bool running, created;
    World* world;
    public:
    Session(): running(true), created(false) {
    }
    void newWorld(int x, int y) {
        world = new World(x,y);
        created = true;
    }
    bool sessionRunning() {return running;}
    bool worldCreated() {return created;}
    void loadWorld(int input) {
        ifstream load("save.txt");
        int x,y;
        load>>x>>y;
        newWorld(x,y);
        int i = 0;
        Organism* o;
        char symbol;
        Pos pos;
        while(!load.eof()) {
            load>>symbol;
            load>>pos;
            world->create(symbol,pos);
            o = world->getCanvas()->operator[](i);
            load>>o;
        }
    }
    void rand() {
        world->generate();
    }
    void manage() {
        world->drawWorld();
        world->makeATurn();
    }
};

int main () {
    srand(time(NULL));
    Session session;
    int x,y;

    
    //A {12,4} 8 4 0
    /*World world(20,20);
    char s = 'A';
    cin>>s;
    Pos pos;
    cin>>pos;
    //int si,in,a;
    //cin>>si>>in>>a;
    //cout<<s<<" "<<pos<<" "<<si<<" "<<in<<" "<<a<<'\n';
    world.create(s,pos);
    Organism* o = world.getCanvas()->operator[](0);
    //cout<<o;
    cin>>o;
    cout<<o;*/

    initscr();
    while(session.sessionRunning()) {
        printw("l - wczytaj, n - nowa\n");
        switch(getch()) {
            case LOAD:{
                printw("slot(1-3)");
                refresh();
                int input = getch();
                while(input < 1 && input > 3) {
                    printw("slot(1-3");
                    refresh();
                    input = getch();
                }
                session.loadWorld(input);
                break;
            } 
            case NEW:{
                printw("rozmiaty swiata: ");
                refresh();
                scanw("%i %i",&x,&y);
                session.newWorld(x,y);
                session.rand();
                break;
            }
        }
        while(session.worldCreated())
            session.manage();
    }
    endwin();
    return 0;
}