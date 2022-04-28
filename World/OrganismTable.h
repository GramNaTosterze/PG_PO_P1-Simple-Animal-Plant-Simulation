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
    void add(Human*);
    void remove(Human*);
    void add(Organism*);
    void remove(Organism*);
    Organism* find(char);
    void clear();
    void qsort(int, int);
    void sort();
    void save(int,int,int);
    unsigned int size() const;
};