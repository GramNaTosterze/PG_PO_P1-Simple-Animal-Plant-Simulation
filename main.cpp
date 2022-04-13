#include <iostream>
#include "World/World.h"
#include "World/Organisms/Organism.h"
#include "World/Organisms/Plant.h"
#include "World/Organisms/Animal.h"

#include "World/Organisms/Animals/Human.h"
#include "defines.h"

using namespace std;

int main () {
    int a;

    World world(BOARDX,BOARDY,1);
    world.addOrganism(new Human(10,10,{2,2},world.getCanvas(),CZLOWIEK));
    while(true) {
        world.drawWorld();
        world.makeATurn();
    }


    return 0;
}