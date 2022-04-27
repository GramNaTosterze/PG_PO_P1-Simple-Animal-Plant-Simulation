
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
void OrganismTable::remove(Organism* toRemove) {
    int i = 0;
    currentSize--;
    for(i; table[i] != toRemove; i++);

    for(i; i < currentSize; i++)
        table[i] = table[i+1];

    table[currentSize+1] = nullptr;
    delete toRemove;
    sort(0,currentSize);
}
void OrganismTable::add(Human* h) {
    human = h;
    add((Organism*)h);
    sort(0,currentSize);

}
void OrganismTable::add(Organism* a) {
    table[currentSize] = a;
    currentSize++;
    sort(0,currentSize);
}
void OrganismTable::clear() {
    for(int i = 0; i < currentSize; i++)
        table[i] = nullptr;
    currentSize = 0;
}
void OrganismTable::sort(int l, int r) {
    for(int i = 0; i < r; i++)
        for(int j = i; j < r; j++) {
            if(table[i]->getInitiative() < table[j]->getInitiative())
                swap(table[i],table[j]);
            else if(table[i]->getInitiative() == table[j]->getInitiative())
                if(table[i]->getAge() < table[j]->getAge())
                    swap(table[i],table[j]);
        }
    /*if(r <= l)
        return;
    int i = l-1, j = r+1;
    Organism* pivot = table[(l+r)/2];
    while(true) {
        while((pivot->getInitiative() > table[++i]->getInitiative()) );//|| (pivot->getInitiative() == table[i]->getInitiative() && pivot->getAge() > table[i]->getAge()));
        while((pivot->getInitiative() < table[--j]->getInitiative()) );//|| (pivot->getInitiative() == table[j]->getInitiative() && pivot->getAge() < table[j]->getAge()));
        if( i < j)
            swap(table[i],table[j]);
        else
            break;

    }
    if(j > l)
        sort(l,j);
    if(i < r)
        sort(i,r);*/
}
unsigned int OrganismTable::size() const{return currentSize;}
void OrganismTable::save(int input,int x, int y) {
    ofstream save("save.txt");
    save<<x<<" "<<y<<'\n';
    for(int i = 0; i < currentSize; i++) {
        save<<table[i]<<'\n';
    }
    save.close();
}