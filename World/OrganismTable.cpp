
#include <iostream>
#include <fstream>
#include "OrganismTable.h"
#include "Organisms/Organism.h"
#include "Organisms/Animal.h"
#include "Organisms/Organisms.h"
#include "Canvas.h"
OrganismTable::OrganismTable(unsigned int x): table(new Organism*[x]) {
    for(int i = 0; i < x; i++)
        table[i] = nullptr;
}
Organism* OrganismTable::operator[](unsigned int i) const{return table[i];}
Human* OrganismTable::getHuman() const{return human;}
void OrganismTable::remove(Organism* toRemove) {
    int i = 0;
    currentSize--;
    for(i; table[i] != toRemove; i++);

    for(i; i < currentSize; i++)
        table[i] = table[i+1];

    table[currentSize+1] = nullptr;
    delete toRemove;
    //sort(0,currentSize);
}
void OrganismTable::add(Human* h) {
    human = h;
    add((Organism*)h);
}
void OrganismTable::add(Organism* a) {
    table[currentSize] = a;
    currentSize++;
    //sort(0,currentSize);
}
void OrganismTable::create(Organism* organism, char symbol,Canvas* world) {
    switch(symbol){
        case HUMAN:{
            organism = new Human({0,0},world);
            return;
        }
        case ANTELOPE:{
            organism = new Antelope({0,0},world);
            return;
        }
        /*case CYBER_SHEEP:{
            organism = new CyberSheep({0,0},world);
            return;
        }*/
        case FOX:{
            organism = new Fox({0,0},world);
            return;
        }
        case SHEEP:{
            organism = new Sheep({0,0},world);
            return;
        }
        case TURTLE:{
            organism = new Turtle({0,0},world);
            return;
        }
        case WOLF:{
            organism = new Wolf({0,0},world);
            return;
        }
        case ATROPA_BELLADONNA:{
            organism = new AtropaBelladonna({0,0},world);
            return;
        }
        case DANDELION:{
            organism = new Dandelion({0,0},world);
            return;
        }
        case GRASS:{
            organism = new Grass({0,0},world);
            return;
        }
        case GUARANA:{
            organism = new Guarana({0,0},world);
            return;
        }
        case HERACLEUM_SOSNOWSKYI:{
            organism = new HeracleumSosnowskyi({0,0},world);
            return;
        }
    }
}
void OrganismTable::clear() {
    for(int i = 0; i < currentSize; i++)
        table[i] = nullptr;
    currentSize = 0;
}
void OrganismTable::sort(int l, int r) {
    if(r <= l)
        return;
    int i = l-1, j = r+1;
    Organism* pivot = table[(l+r)/2];
    while(true) {
        while((pivot->getInitiative() > table[++i]->getInitiative()) || (pivot->getInitiative() == table[i]->getInitiative() && pivot->getAge() > table[i]->getAge()));
        while((pivot->getInitiative() < table[--j]->getInitiative()) || (pivot->getInitiative() == table[j]->getInitiative() && pivot->getAge() < table[j]->getAge()));
        if( i < j)
            swap(table[i],table[j]);
        else
            break;

    }
    if(j > l)
        sort(l,j);
    if(i < r)
        sort(i,r);
}
unsigned int OrganismTable::size() const{return currentSize;}
void OrganismTable::save(int input) {
    ofstream save("save.txt");
    for(int i = 0; i < currentSize; i++) {
        save<<table[i]<<'\n';
    }
    save.close();
}
void OrganismTable::load(int input, Canvas* world) {
    ifstream load("save.txt");
    clear();
    int i = 0;
    char symbol;
    while(!load.eof()) {
        load>>symbol;
        create(table[i],symbol,world);
        load>>table[i];
    }
    currentSize = i;
}