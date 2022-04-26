#pragma once
#include "Sheep.h"

class CyberSheep : public Sheep {
    public:
    CyberSheep(Pos, Canvas*);
    string getName() const override;
    void action() override;
    void colision(Plant*) override;
};