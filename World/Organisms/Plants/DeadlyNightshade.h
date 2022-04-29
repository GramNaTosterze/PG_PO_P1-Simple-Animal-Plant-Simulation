
#include "../Plant.h"

class DeadlyNightshade : public Plant{
    public:
    DeadlyNightshade(Pos, Canvas*);
    void addInstanceOf(Pos) override;
    void colision(Animal*) override;
};