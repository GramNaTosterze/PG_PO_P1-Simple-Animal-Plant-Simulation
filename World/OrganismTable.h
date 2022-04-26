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
    void create(Organism*,char,Canvas*);
    void clear();
    void sort(int, int);
    void save(int);
    void load(int,Canvas*);
    unsigned int size() const;
};