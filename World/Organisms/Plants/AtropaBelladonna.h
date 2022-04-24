
#include "../Plant.h"

class AtropaBelladonna : public Plant{
    public:
    AtropaBelladonna(Pos, Canvas*,Info*);
    void addInstanceOf(Pos) override;
    void colision(Animal*) override;
};