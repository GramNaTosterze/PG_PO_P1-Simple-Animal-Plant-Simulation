#pragma once

class Organism;
class Human;
class Animal;
class Canvas;

class OrganismTable {
    private:
    Organism** table;
    Human* human;
    unsigned int currentSize;
    public:
    OrganismTable(unsigned int);
    Organism* operator[](unsigned int) const;
    Human* getHuman() const;
    void remove(Organism*);
    void add(Human*);
    void add(Organism*);
    void clear();
    void sort(int, int);
    void save(int,int,int);
    unsigned int size() const;
};