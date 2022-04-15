#pragma once

class Organism;
class Animal;

class OrganismTable {
    private:
    Organism** table;
    unsigned int currentSize;
    public:
    OrganismTable(unsigned int x);
    void makeActions();
    Organism* operator[](unsigned int i);
    void remove(Organism* toRemove);
    void add(Animal* a);
    void sort(int l, int p);
    unsigned int size();
};