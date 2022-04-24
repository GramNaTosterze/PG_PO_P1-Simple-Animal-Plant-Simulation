
#include "../Plant.h"

class Guarana : public Plant{
    public:
    Guarana(Pos, Canvas*, Info*);
    void addInstanceOf(Pos) override;
    void colision(Animal*) override;
};