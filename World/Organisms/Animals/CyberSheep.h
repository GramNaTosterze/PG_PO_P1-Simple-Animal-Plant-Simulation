#pragma once
#include "Sheep.h"

class CyberSheep : public Sheep {
    public:
    CyberSheep(Pos position, Canvas *canvas);
    void action() override;
    void colision(Plant* other) override;
};