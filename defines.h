#pragma once

#define BOARDX 20
#define BOARDY 20
#define EMPTY_POS {-1,-1}
enum {
    HUMAN = '&',
    WOLF = '^',
    SHEEP = '-',
    FOX = '!',
    TURTLE = '@',
    ANTELOPE = '/',
    CYBER_SHEEP = '~',

    GRASS = '.',
    DANDELION = '*',
};
enum DIRECTIONS {
    UP=0,
    DOWN,
    LEFT,
    RIGHT,
    STAY,
};