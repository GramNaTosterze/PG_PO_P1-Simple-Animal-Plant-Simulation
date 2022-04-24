
#include "../Plant.h"

class Dandelion : public Plant{
    public:
    Dandelion(Pos, Canvas*, Info*);
    void action() override;
    void addInstanceOf(Pos);
};