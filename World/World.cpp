#include <iostream>
#include "World.h"
using namespace std;

World::World(unsigned int X, unsigned int Y, unsigned int n) :canvas(new Canvas(X,Y)){}
void World::addOrganism(Animal* n) {
    canvas->organismsTable().add(n);
}
void World::addOrganism(Plant* n) {
}
void World::makeATurn() {
    canvas->organismsTable().makeActions();
    //czyszczenie konsoli
    system("clear");
    //cout << "\x1B[2J\x1B[H";
}
void World::drawWorld() {
    cout<<"Liczba Organizmów: "<<canvas->organismsTable().size()<<'\n';
    canvas->draw();
}
Canvas* World::getCanvas() {
    return canvas;
}
World::~World() {

}