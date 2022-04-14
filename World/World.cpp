#include <iostream>
#include "World.h"
using namespace std;

World::World(unsigned int X, unsigned int Y, unsigned int n) :canvas(new Canvas(X,Y)){}
void World::addOrganism(Animal* n) {
    organisms.push_back(n);
}
void World::addOrganism(Plant* n) {
    organisms.push_back(n);
}
void World::makeATurn() {
    for(int i = 0; i < organisms.size(); i++) {
        organisms[i]->action();
    }
    //czyszczenie konsoli
    system("clear");
    //cout << "\x1B[2J\x1B[H";
}
void World::drawWorld() {
    cout<<"Liczba Organizmów: "<<organisms.size()<<'\n';
    canvas->draw();
}
Canvas* World::getCanvas() {
    return canvas;
}
World::~World() {

}