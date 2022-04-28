
#include <iostream>
#include <fstream>
#include "OrganismTable.h"
#include "Organisms/Organism.h"
#include "Organisms/Animal.h"
#include "Canvas.h"
OrganismTable::OrganismTable(unsigned int x): table(new Organism*[x]) {
    for(int i = 0; i < x; i++)
        table[i] = nullptr;
}
Organism* OrganismTable::operator[](unsigned int i) const{return table[i];}
Human* OrganismTable::getHuman() const{return human;}
void OrganismTable::add(Human* h) {
    human = h;
    add((Organism*)human);
}
void OrganismTable::remove(Human* h) {
    human = nullptr;
    remove((Organism*)human);
}
void OrganismTable::add(Organism* a) {
    table[currentSize] = a;
    currentSize++;
}
void OrganismTable::remove(Organism* toRemove) {
    int i = 0;
    currentSize--;
    for(i; table[i] != toRemove; i++);

    for(i; i < currentSize; i++)
        table[i] = table[i+1];

    table[currentSize+1] = nullptr;
    delete toRemove;
}
Organism* OrganismTable::find(char symbol) {
    for(int i = 0; i < currentSize; i++)
        if(table[i]->draw() == symbol)
            return table[i];

    return nullptr;
}
void OrganismTable::clear() {
    for(int i = 0; i < currentSize; i++)
        table[i] = nullptr;
    currentSize = 0;
}
void OrganismTable::sort() {
    qsort(0,currentSize-1);
}
void OrganismTable::qsort(int l, int r) {
    if(r <= l)
        return;
    int i = l-1, j = r+1;
    Organism* pivot = table[(l+r)/2];
    while(true) {
        while((++i)<r && (*(pivot) < *(table[i])));
        while((--j)>l && (*(table[j]) < *(pivot)));
        if( i <= j) {
            Organism* tmp = table[i];
            table[i] = table[j];
            table[j] = tmp;
        }
        else
            break;

    }
    if(j > l)
        qsort(l,j);
    if(i < r)
        qsort(i,r);
}
unsigned int OrganismTable::size() const{return currentSize;}
void OrganismTable::save(int input,int x, int y) {
    ofstream save("save"+to_string(input)+".txt");
    save<<x<<" "<<y<<'\n';
    for(int i = 0; i < currentSize; i++) {
        save<<table[i]<<'\n';
    }
    save.close();
}