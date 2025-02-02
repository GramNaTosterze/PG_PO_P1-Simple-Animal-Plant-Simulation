
#include "Session.h"
#include <fstream>
#include <ncurses.h>

Session::Session(): running(true), created(false) {}
void Session::newWorld(int x, int y, int turn) {
    world = new World(x,y,turn);
    created = true;
}
bool Session::sessionRunning() {return running;}
void Session::end() {
    running = false;
    delete world;
    created = false;
}
bool Session::worldCreated() {return created;}
void Session::loadWorld(int input) {
    ifstream load("save"+to_string(input)+".txt");
    if(load.is_open()) {
        int x,y,turn;
        load>>x>>y;
        load>>turn;
        newWorld(x,y,turn);
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
            i++;
        }
    }
    else 
        printw("\nbrak zapisu na slocie:%i\n",input);
    load.close();
}
void Session::rand() {
    world->generate();
}
void Session::manage() {
    world->turn(created);
}