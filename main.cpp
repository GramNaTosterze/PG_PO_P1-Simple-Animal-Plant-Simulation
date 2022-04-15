#include <iostream>
#include "World/World.h"
#include "World/Organisms/Organism.h"
#include "World/Organisms/Plant.h"
#include "World/Organisms/Animal.h"

#include "World/Organisms/Animals/Human.h"
#include "World/Organisms/Animals/Wolf.h"
#include "World/Organisms/Animals/Sheep.h"
#include "defines.h"

using namespace std;

int main () {
    srand(time(NULL));

    World world(BOARDX,BOARDY,1);

    world.addOrganism(new Human({2,2},world.getCanvas()));
    world.addOrganism(new Wolf({10,10},world.getCanvas()));
    world.addOrganism(new Sheep({15,12},world.getCanvas()));


    while(true) {
        world.drawWorld();
        world.makeATurn();
    }


    return 0;
}