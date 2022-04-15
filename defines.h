#pragma once

#define BOARDX 20
#define BOARDY 20
enum {
    HUMAN = '&',
    WOLF = '#',
    SHEEP = '-',
    FOX = '!',
    TURTLE = '@',
    ANTELOPE = '/',
    CYBER_SHEEP = '~',

    GRASS = '.',
};
enum DIRECTIONS {
    UP=0,
    DOWN,
    LEFT,
    RIGHT,
    STAY,
};