#include <iostream>
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


//przykładowe zwierzęta można wywalić do klasy World dodatkowo
    world.addOrganism(new Human({2,2},world.getCanvas()));
    world.addOrganism(new Wolf({10,10},world.getCanvas()));
    world.addOrganism(new Turtle({16,10},world.getCanvas()));
    world.addOrganism(new Fox({11,10},world.getCanvas()));
    world.addOrganism(new Sheep({15,12},world.getCanvas()));
//przykładowe rośliny można wywalić do klasy World dodatkowo
    world.addOrganism(new Grass({0,0},world.getCanvas()));
    world.addOrganism(new Dandelion({4,4},world.getCanvas()));


    while(true) {
        world.drawWorld();
        world.makeATurn();
    }


    return 0;
}