#include <iostream>
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
Pos Canvas::findEmpty(Pos pos) {
    if(board[pos.y+1][pos.x] == nullptr)
        return {pos.x,pos.y+1};
    if(board[pos.y-1][pos.x] == nullptr)
        return {pos.x,pos.y-1};
    if(board[pos.y][pos.x+1] == nullptr)
        return {pos.x+1,pos.y};
    if(board[pos.y][pos.x-1] == nullptr)
        return {pos.x-1,pos.y+1};
    
    return {-1,-1};
}
OrganismTable& Canvas::organismsTable() {
    return organisms;
}
unsigned int Canvas::getX() {
    return X;
}
unsigned int Canvas::getY() {
    return Y;
}
void Canvas::set(Pos pos, Animal* organism) {
    board[pos.y][pos.x] = organism;
    //organism->setPosition(pos);
}
void Canvas::set(Pos pos, Plant* organism) {
    board[pos.y][pos.x] = organism;
}
void Canvas::check_colision() {

}
void Canvas::draw() {
    unsigned int x = getX(), y = getY();
    for(int i = 0; i < y; i++) {
        for( int j = 0; j < x; j++)
            cout<<(board[i][j] != nullptr ? board[i][j]->draw() : '_');
        cout<<'\n';
    }
}