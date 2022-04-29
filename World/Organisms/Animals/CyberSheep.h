#pragma once
#include "Sheep.h"
#include "../Plant.h"

class CyberSheep : public Sheep {
    private:
    Pos destination;
    public:
    CyberSheep(Pos, Canvas*);
    void addInstanceOf(Pos) override;
    void action() override;
    void colision(Plant*) override;
};