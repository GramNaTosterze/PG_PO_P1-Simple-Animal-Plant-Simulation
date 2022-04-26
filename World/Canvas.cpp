
#include <ncurses.h>
#include "Canvas.h"
#include "Organisms/Plant.h"
#include "Organisms/Animal.h"
#include "../defines.h"

using namespace std;

Canvas::Canvas(unsigned int X, unsigned int Y) : X(X), Y(Y), board(new Organism**[X]), organisms(X*Y){
    for(int i = 0; i < Y; i++)
        board[i] = new Organism*[X];

    for(int i = 0; i < Y; i++)
        for(int j = 0; j < X; j++)
            board[i][j] = nullptr;
}
Organism* Canvas::operator[] (unsigned int i) {
    return organisms[i];
}
Organism* Canvas::operator[] (Pos pos) {
    return board[pos.y][pos.x];
}
Pos Canvas::nextPos(Pos pos) {
    DIRECTIONS direction = DIRECTIONS(rand()%4);
    switch(direction) {
        case UP: {
            if(pos.y+1 != BOARDY && board[pos.y+1][pos.x] == nullptr)
                return {pos.x,pos.y+1};
        }
        case DOWN: {
            if(pos.y-1 != -1 && board[pos.y-1][pos.x] == nullptr)
                return {pos.x,pos.y-1};
        }
        case LEFT: {
            if(pos.x+1 != BOARDX && board[pos.y][pos.x+1] == nullptr)
                return {pos.x+1,pos.y};
        }
        case RIGHT: {
            if(pos.x-1 != -1 && board[pos.y][pos.x-1] == nullptr)
                return {pos.x-1,pos.y};
        }
    }
    return EMPTY_POS;
}
void Canvas::addInfoUp(string info) {infoUp = infoUp + info;}
void Canvas::addInfoDown(string info) {infoDown = infoDown + info;}
OrganismTable& Canvas::organismsTable() {return organisms;}
unsigned int Canvas::getX() {return X;}
unsigned int Canvas::getY() {return Y;}
void Canvas::set(Pos pos, Organism* organism) {board[pos.y][pos.x] = organism;}
void Canvas::cleanInfo() {
    infoUp.clear();
    infoDown.clear();
}
void Canvas::draw() {
    clear();
    //refresh();
    printw("Krzysztof Napiórkowski 191689\n");
    printw("Liczba Organizmów: %u\n",organismsTable().size());
    char* up = &infoUp[0];
    printw("%s",up);
    unsigned int x = getX(), y = getY();
    for(int i = 0; i <= y+1; i++) {
        for( int j = 0; j <= x+1; j++) {
            if(i == 0 || i == y+1 || j == 0 || j == x+1)
                printw("#");
            else {
                if(board[i-1][j-1] != nullptr) {
                    const char c[1] = {board[i-1][j-1]->draw()};
                    printw(c);
                }
                else
                    printw(" ");
            }
        }
        printw("\n");
    }
    char* down = &infoDown[0];
    printw("%s",down);
    cleanInfo();
    refresh();
}