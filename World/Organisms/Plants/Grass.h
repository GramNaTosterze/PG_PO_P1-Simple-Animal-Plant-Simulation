
#include "../Plant.h"

class Grass : public Plant{
    public:
    Grass(Pos, Canvas*,Info*);
    void addInstanceOf(Pos) override;
};