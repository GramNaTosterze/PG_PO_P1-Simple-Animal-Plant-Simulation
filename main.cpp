#include <iostream>
#include "World/World.h"
#include "World/Organisms/Organism.h"
#include "World/Organisms/Plant.h"
#include "World/Organisms/Animal.h"
#include "defines.h"

using namespace std;

int main () {
    int a;

    World world(boardX,boardY,1);
    while(true) {
        

        world.drawWorld();
        cin>>a;
        world.makeATurn();
    }


    return 0;
}