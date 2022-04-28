
#include "Position.h"

bool Pos::operator!=(Pos pos) {
    return (x != pos.x || y != pos.y);
}
ostream& operator<<(ostream& out, const Pos pos) {
    out<<pos.x<<' '<<pos.y;
    return out;
}
istream& operator>>(istream& in, Pos& pos) {
    in>>pos.x>>pos.y;
    return in;
}