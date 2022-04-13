#include <iostream>
#include "World.h"
using namespace std;

World::World(unsigned int X, unsigned int Y, unsigned int n) :canvas(X,Y){}
void World::makeATurn() {
    //czyszczenie konsoli
    cout << "\x1B[2J\x1B[H";
}
void World::drawWorld() {
    cout<<"Liczba Organizmów: "<<0<<'\n';
    canvas.draw();
}
World::~World() {

}