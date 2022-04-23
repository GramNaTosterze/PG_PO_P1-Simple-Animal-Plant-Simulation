
#include "../Plant.h"

class Grass : public Plant{
    public:
    Grass(Pos position, Canvas* canvas);
    void addInstanceOf(Pos pos) override;
};