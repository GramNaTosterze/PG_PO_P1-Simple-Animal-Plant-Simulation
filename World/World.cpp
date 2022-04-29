#include "World.h"
#include "Organisms/Organisms.h"
#include <ncurses.h>
using namespace std;
World::World(unsigned int X, unsigned int Y, unsigned int T) :canvas(new Canvas(X,Y)), currentTurn(T) {}
World::World(unsigned int X, unsigned int Y) :World(X,Y,1) {}
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
        case CYBER_SHEEP:{
            addOrganism<CyberSheep>(pos);
            return;
        }
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
        case DEADLY_NIGHTSHADE:{
            addOrganism<DeadlyNightshade>(pos);
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
        case SOSNOWSKYS_HOGWEED:{
            addOrganism<SosnowskysHogweed>(pos);
            return;
        }
    }
    return;
}
char World::randAnimal() {
    char animals[6] = {WOLF,SHEEP,FOX,TURTLE,ANTELOPE,CYBER_SHEEP};
    int r = rand()%6;
    return animals[r];
}
char World::randPlant() {
    char plants[5] = {GRASS,DANDELION,GUARANA,DEADLY_NIGHTSHADE,SOSNOWSKYS_HOGWEED};
    int r = rand()%5;
    return plants[r];
}
void World::generate() {
    int animals = canvas->getX()/3;
    int plants = canvas->getY()/3;
    create(HUMAN,canvas->freeSpace());
    for(int i = 0; i < animals; i++)
        create(randAnimal(),canvas->freeSpace());
    for(int i = 0; i < plants; i++)
        create(randPlant(),canvas->freeSpace());
}
template <class Organisms>
void World::addOrganism(Pos pos) {
    canvas->organismsTable().add(new Organisms(pos,canvas));
}
void World::turn(bool& wrd) {
    Human* human = canvas->organismsTable().getHuman();
    if(human != nullptr)
        canvas->addInfoUp("kontrola czlowieka - strzalki, ");
    canvas->addInfoUp("zapis - s, nastepna tura - spacja, powrot - b");
    canvas->addInfoUp("Tura "+to_string(currentTurn));
    canvas->draw();
    canvas->organismsTable().sort();
    int input = -1;
    while(input != NEXT_TURN) {
        input = getch();
        switch(input){
            case ARROWS:{
                if(human!= nullptr)
                    human->control(input);
                break;
            }
            case NEXT_TURN:{
                currentTurn++;
                for(int i = 0; i < canvas->organismsTable().size(); i++)
                    (*canvas)[i]->action();
                break;
            }
            case SAVE:{
                save(input);
                break;
            }
            case BACK:{
                wrd = false;
                return;
            }
        }
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
    canvas->organismsTable().save(save,canvas->getX(),canvas->getY(),currentTurn);
    input = NEXT_TURN;
}
World::~World() {
    delete canvas;
}