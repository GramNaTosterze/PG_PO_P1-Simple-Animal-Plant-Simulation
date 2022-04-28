#pragma once
#include "World.h"
#include "Organisms/Organism.h"

class Session{
    private:
    bool running, created;
    World* world;
    public:
    Session();
    void newWorld(int, int);
    bool sessionRunning();
    void end();
    bool worldCreated();
    void loadWorld(int);
    void rand();
    void manage();
};