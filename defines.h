#pragma once

#define BOARDX 20
#define BOARDY 20
#define EMPTY_POS {-1,-1}


#define EXIT 120
#define SAVE 115
#define LOAD 108
#define NEW 110

#define ARROWS 27

#define K_UP 'D'
#define K_DOWN 'C'
#define K_LEFT 'A'
#define K_RIGHT 'B'
#define ABILITY 112
#define ABILITY2 80

enum {
    HUMAN = 'A',
    WOLF = 'H',
    SHEEP = 'O',
    FOX = 'W',
    TURTLE = 'U',
    ANTELOPE = 'M',
    CYBER_SHEEP = 'Q',

    GRASS = '.',
    DANDELION = '*',
    GUARANA = '+',
    ATROPA_BELLADONNA = '!',
    HERACLEUM_SOSNOWSKYI = 'x'
};
enum DIRECTIONS {
    UP=0,
    DOWN,
    LEFT,
    RIGHT,
    STAY,
};