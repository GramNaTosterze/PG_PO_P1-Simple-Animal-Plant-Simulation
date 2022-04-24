#include "World.h"
using namespace std;

World::World(unsigned int X, unsigned int Y, unsigned int n) :canvas(new Canvas(X,Y)) {
}
void World::addOrganism(Organism* n) {
    canvas->organismsTable().add(n);
}
void World::makeATurn() {
    canvas->organismsTable().makeActions();
}
void World::drawWorld() {
    info.setCurrentOrganismNumber(canvas->organismsTable().size());
    info.print();
    canvas->draw();
}
Canvas* World::getCanvas() {
    return canvas;
}
Info* World::getInfo() {
    return &info;
}
World::~World() {
    delete canvas;
}