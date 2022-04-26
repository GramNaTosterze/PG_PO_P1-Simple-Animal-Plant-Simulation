
#include "../Plant.h"

class AtropaBelladonna : public Plant{
    public:
    AtropaBelladonna(Pos, Canvas*);
    void addInstanceOf(Pos) override;
    void colision(Animal*) override;
};