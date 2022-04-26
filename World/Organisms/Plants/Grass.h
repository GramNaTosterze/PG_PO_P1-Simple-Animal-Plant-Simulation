
#include "../Plant.h"

class Grass : public Plant{
    public:
    Grass(Pos, Canvas*);
    void addInstanceOf(Pos) override;
};