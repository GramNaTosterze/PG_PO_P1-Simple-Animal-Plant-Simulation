#pragma once
#include <iostream>
using namespace std;
struct Pos{
    public:
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
    friend ostream& operator<<(ostream& out, const Pos pos) {
        out<<pos.x<<' '<<pos.y;
        return out;
    }
    friend istream& operator>>(istream& in, Pos& pos) {
        in>>pos.x>>pos.y;
        return in;
    }
};