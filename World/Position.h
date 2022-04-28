#pragma once
#include <iostream>
using namespace std;
struct Pos{
    public:
    int x;
    int y;
    bool operator!=(Pos pos);
    friend ostream& operator<<(ostream& out, const Pos pos);
    friend istream& operator>>(istream& in, Pos& pos);
};