
#include "OrganismTable.h"
#include "Organisms/Organism.h"
#include "Organisms/Animal.h"

OrganismTable::OrganismTable(unsigned int x): table(new Organism*[x]) {
    for(int i = 0; i < x; i++)
        table[i] = nullptr;
}
void OrganismTable::makeActions() {
    for(int i = 0; i < currentSize; i++)
        table[i]->action();
}
Organism* OrganismTable::operator[](unsigned int i) {
    return table[i];
}
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
void OrganismTable::add(Animal* a) {
    table[currentSize] = a;
    currentSize++;
    //sort(0,currentSize);

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
unsigned int OrganismTable::size() {
    return currentSize;
}