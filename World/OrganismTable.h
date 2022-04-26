#pragma once

class Organism;
class Human;
class Animal;

class OrganismTable {
    private:
    Organism** table;
    Human* human;
    unsigned int currentSize;
    public:
    OrganismTable(unsigned int);
    Organism* operator[](unsigned int);
    Human* getHuman();
    void remove(Organism*);
    void add(Human*);
    void add(Organism*);
    void sort(int, int);
    void save();
    void load();
    unsigned int size();
};