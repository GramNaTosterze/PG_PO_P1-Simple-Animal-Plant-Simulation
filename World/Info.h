#pragma once
#include <string>
using namespace std;

class Info {
    string info;
    unsigned int currentOrganismNumber;
    public:
    void addInfo(string);
    void setCurrentOrganismNumber(unsigned int);
    void clear();
    void print();
};