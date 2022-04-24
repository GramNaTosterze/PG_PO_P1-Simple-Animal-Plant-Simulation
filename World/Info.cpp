
#include <ncurses.h>
#include "Info.h"
void Info::addInfo(string s) {
    info = info + s;
}
void Info::setCurrentOrganismNumber(unsigned int number) {
    currentOrganismNumber = number;
}
void Info::clear() {
    info.clear();
}
void Info::print() {
    erase();
    refresh();
    printw("Krzysztof Napiórkowski 191689\n");
    printw("Liczba Organizmów: %u\n",currentOrganismNumber);
    char* c;
    c = &info[0];
    printw("%s",c);
    info.clear();
}