#pragma once

class Session{
    private:
    bool running, created;
    World* world;
    public:
    Session(): running(true), created(false) {}
    void newWorld(int x, int y) {
        world = new World(x,y);
        created = true;
    }
    bool sessionRunning() {return running;}
    void end() {
        running = false;
        delete world;
        created = false;
        }
    bool worldCreated() {return created;}
    void loadWorld(int input) {
        ifstream load("save"+to_string(input)+".txt");
        if(load.is_open()) {
            int x,y;
            load>>x>>y;
            newWorld(x,y);
            int i = 0;
            Organism* o;
            char symbol;
            Pos pos;
            while(!load.eof()) {
                load>>symbol;
                load>>pos;
                world->create(symbol,pos);
                o = world->getCanvas()->operator[](i);
                load>>o;
            }
        }
        else 
            printw("\nbrak zapisu na slocie:%i\n",input);
        load.close();
    }
    void rand() {
        world->generate();
    }
    void manage() {
        world->turn();
    }
};