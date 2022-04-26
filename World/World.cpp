#include "World.h"
#include "Organisms/Animals/Human.h"
#include <ncurses.h>
using namespace std;

World::World(unsigned int X, unsigned int Y, unsigned int n) :canvas(new Canvas(X,Y)) {
}
void World::addOrganism(Organism* n) {
    canvas->organismsTable().add(n);
}
void World::makeATurn() {
    int input = -1;
    while(input != NEXT_TURN) {
        input = getch();
        if(input == ARROWS)
            ((Human*)((*canvas)[0]))->control(input);
        else if (input == NEXT_TURN)
            for(int i = 0; i < canvas->organismsTable().size(); i++)
                (*canvas)[i]->action();
        else if (input == SAVE)
            save();
        else if (input == LOAD)
            load();
    }
}
void World::drawWorld() {
    canvas->draw();
}
Canvas* World::getCanvas() {
    return canvas;
}
void World::save() {
    int input = -1;
    while(input < 1 && input > 3) {
        clear();
        printw("slot(1-3)");
        refresh();
        int input = getch();
    }
    canvas->organismsTable().save();
}
void World::load() {

}
World::~World() {
    delete canvas;
}