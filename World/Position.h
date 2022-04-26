#pragma once
#include <iostream>
using namespace std;
struct Pos{
    int x;
    int y;
    bool operator!=(Pos pos) {
        if(this->x != pos.x)
            return true;
        else if(this->y != pos.y)
            return true;
        else
            return false;
    }
    friend ostream& operator<<(ostream& out, Pos pos) {
        out<<'{'<<pos.x<<','<<pos.y<<'}';
        return out;
    }
};