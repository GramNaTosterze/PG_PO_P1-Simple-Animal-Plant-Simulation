#include <iostream>
#include "Canvas.h"
using namespace std;

Canvas::Canvas(unsigned int X, unsigned int Y) : X(X), Y(Y), board(new char*[X]){
    for(int i = 0; i < X; i++)
        board[i] = new char[Y];

    for(int i = 0; i < X; i++)
        for(int j = 0; j < Y; j++)
            board[i][j] = '_';
}
unsigned int Canvas::getX() {
    return X;
}
unsigned int Canvas::getY() {
    return Y;
}
void Canvas::set(Pos pos, char s) {
    board[pos.x][pos.y] = s;
}
void Canvas::check_colision() {

}
void Canvas::draw() {
    unsigned int x = getX(), y = getY();
    for(int i = 0; i < x; i++) {
        for( int j = 0; j < y; j++)
            cout<<board[i][j];
        cout<<'\n';
    }
}