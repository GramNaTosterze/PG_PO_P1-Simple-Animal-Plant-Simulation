#pragma once
#include "../Plant.h"

class SosnowskysHogweed : public Plant{
    public:
    SosnowskysHogweed(Pos, Canvas*);
    void addInstanceOf(Pos) override;
    void action() override;
    void colision(Human*);
    void colision(Animal*) override;
};