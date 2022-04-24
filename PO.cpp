#include <iostream>
#include <ncurses.h>
#include "World/World.h"
#include "World/Organisms/Organism.h"
#include "World/Organisms/Plant.h"
#include "World/Organisms/Animal.h"

#include "World/Organisms/Animals/Human.h"
#include "World/Organisms/Animals/Wolf.h"
#include "World/Organisms/Animals/Sheep.h"
#include "World/Organisms/Animals/Turtle.h"
#include "World/Organisms/Animals/Antelope.h"
#include "World/Organisms/Animals/Fox.h"
#include "World/Organisms/Animals/CyberSheep.h"

#include "World/Organisms/Plants/Grass.h"
#include "World/Organisms/Plants/Dandelion.h"
#include "defines.h"

using namespace std;

int main () {
    srand(time(NULL));

    World world(BOARDX,BOARDY,1);

    Canvas* canvas =  world.getCanvas();
    Info* info = world.getInfo();
//przykładowe zwierzęta można wywalić do klasy World dodatkowo
    world.addOrganism(new Human({2,2},canvas,info));
    world.addOrganism(new Wolf({10,10},canvas,info));
    world.addOrganism(new Turtle({16,10},canvas,info));
    world.addOrganism(new Fox({11,10},canvas,info));
    world.addOrganism(new Sheep({15,12},canvas,info));
//przykładowe rośliny można wywalić do klasy World dodatkowo
    world.addOrganism(new Grass({0,0},canvas,info));
    world.addOrganism(new Dandelion({4,4},canvas,info));

    initscr();
    while(true) {
        world.drawWorld();
        world.makeATurn();
    }
    endwin();

    return 0;
}