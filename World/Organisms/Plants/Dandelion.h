
#include "../Plant.h"

class Dandelion : public Plant{
    public:
    Dandelion(Pos position, Canvas* canvas);
    void action() override;
    void addInstanceOf(Pos pos);
};