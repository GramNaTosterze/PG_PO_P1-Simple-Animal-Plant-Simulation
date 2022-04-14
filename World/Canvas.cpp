#include <iostream>
#include "Canvas.h"
#include "Organisms/Plant.h"
#include "Organisms/Animal.h"

using namespace std;

Canvas::Canvas(unsigned int X, unsigned int Y) : X(X), Y(Y), board(new Organism**[X]){
    for(int i = 0; i < Y; i++)
        board[i] = new Organism*[X];

    for(int i = 0; i < Y; i++)
        for(int j = 0; j < X; j++)
            board[i][j] = nullptr;
}
unsigned int Canvas::getX() {
    return X;
}
unsigned int Canvas::getY() {
    return Y;
}
void Canvas::set(Pos pos, Animal* organism) {
    board[pos.y][pos.x] = organism;
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