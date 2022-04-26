
#include "../Plant.h"

class Dandelion : public Plant{
    public:
    Dandelion(Pos, Canvas*);
    void action() override;
    void addInstanceOf(Pos);
};