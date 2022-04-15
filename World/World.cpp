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
void World::sort(int l, int r) {
    if(r <= l)
        return;
    int i = l-1, j = r+1;
    Organism* pivot = organisms[(l+r)/2];
    while(true) {
        while((pivot->getInitiative() > organisms[++i]->getInitiative()) || (pivot->getInitiative() == organisms[i]->getInitiative() && pivot->getAge() > organisms[i]->getAge()));
        while((pivot->getInitiative() < organisms[--j]->getInitiative()) || (pivot->getInitiative() == organisms[j]->getInitiative() && pivot->getAge() < organisms[j]->getAge()));
        if( i < j)
            swap(organisms[i],organisms[j]);
        else
            break;

    }
    if(j > l)
        sort(l,j);
    if(i < r)
        sort(i,r);

}
World::~World() {

}