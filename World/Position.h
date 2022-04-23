#pragma once
struct Pos{
    int x;
    int y;
    bool operator!=(Pos pos) {
        if(this->x != pos.x)
            return false;
        else if(this->y != pos.y)
            return false;
        else
            return true;
    }
};