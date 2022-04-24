
#include "../Plant.h"

class HeracleumSosnowskyi : public Plant{
    public:
    HeracleumSosnowskyi(Pos, Canvas*,Info*);
    void addInstanceOf(Pos) override;
    void action() override;
    void colision(Animal*) override;
};