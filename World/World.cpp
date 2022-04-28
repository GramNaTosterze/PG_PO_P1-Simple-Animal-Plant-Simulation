#include "World.h"
#include "Organisms/Organisms.h"
#include <ncurses.h>
using namespace std;

World::World(unsigned int X, unsigned int Y) :canvas(new Canvas(X,Y)) {}
void World::create(char symbol, Pos pos) {
    switch(symbol){
        case HUMAN:{
            addOrganism<Human>(pos);
            return;
        }
        case ANTELOPE:{
            addOrganism<Antelope>(pos);
            return;
        }
        //case CYBER_SHEEP:{
        //    addOrganism<CyberSheep>(pos);
        //    return;
        //}
        case FOX:{
            addOrganism<Fox>(pos);                
            return;
        }
        case SHEEP:{
            addOrganism<Sheep>(pos);
            return;
        }
        case TURTLE:{
            addOrganism<Turtle>(pos);
            return;
        }
        case WOLF:{
            addOrganism<Wolf>(pos);
            return;
        }
        case ATROPA_BELLADONNA:{
            addOrganism<AtropaBelladonna>(pos);
            return;
        }
        case DANDELION:{
            addOrganism<Dandelion>(pos);
            return;
        }
        case GRASS:{
            addOrganism<Grass>(pos);
            return;
        }
        case GUARANA:{
            addOrganism<Guarana>(pos);
            return;
        }
        case HERACLEUM_SOSNOWSKYI:{
            addOrganism<HeracleumSosnowskyi>(pos);
            return;
        }
    }
    return;
}
char World::randOrganism() {
    return 'a';
}
void World::generate() {
    int number = canvas->getX()/2;
    int x = canvas->getX()-1, y = canvas->getY()-1;
    create(HUMAN,{x/2,y/2});
    create(WOLF,{x/4,y/3});
    create(SHEEP,{x/3,y/4});
    create(ANTELOPE,{x/5,y/2});
    create(TURTLE,{2,2});
    create(FOX,{10,10});

    create(GRASS,{0,0});
    create(DANDELION,{3,3});
    create(ATROPA_BELLADONNA,{x,0});
    create(GUARANA,{6,6});
    create(HERACLEUM_SOSNOWSKYI,{0,y});
    //create(HUMAN,canvas->freeSpace());
    //for(int i = 0; i < number; i++)
    //    create(randOrganism(),canvas->freeSpace());
}
template <class Organisms>
void World::addOrganism(Pos pos) {
    canvas->organismsTable().add(new Organisms(pos,canvas));
}
void World::turn() {
    canvas->draw();
    canvas->organismsTable().sort();
    int input = -1;
    while(input != NEXT_TURN) {
        input = getch();
        Human* human = canvas->organismsTable().getHuman();
        if(input == ARROWS && human != nullptr)
            human->control(input);
        else if (input == NEXT_TURN)
            for(int i = 0; i < canvas->organismsTable().size(); i++)
                (*canvas)[i]->action();
        else if (input == SAVE)
            save(input);
    }
}
Canvas* World::getCanvas() {return canvas;}
void World::save(int& input) {
    int save = -1;
    while(save < 1 || save > 3) {
        clear();
        printw("slot(1-3)");
        refresh();
        save = getch() - '0';
        printw("\n%i\n",save);
        printw("\n");
    }
    canvas->organismsTable().save(save,canvas->getX(),canvas->getY());
    input = NEXT_TURN;
}
World::~World() {
    delete canvas;
}