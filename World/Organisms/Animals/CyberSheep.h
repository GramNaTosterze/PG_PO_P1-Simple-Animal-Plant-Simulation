#pragma once
#include "Sheep.h"

class CyberSheep : public Sheep {
    private:
    Pos destination;
    public:
    CyberSheep(Pos, Canvas*);
    void action() override;
    void colision(Plant*) override;
};