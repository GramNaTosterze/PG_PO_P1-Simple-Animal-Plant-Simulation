#pragma once
#include "Sheep.h"

class CyberSheep : public Sheep {
    public:
    CyberSheep(Pos, Canvas*);
    void action() override;
    void colision(Plant*) override;
};