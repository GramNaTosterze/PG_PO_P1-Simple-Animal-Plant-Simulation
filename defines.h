#pragma once

#define EMPTY_POS {-1,-1}
#define ARROWS 27
#define K_UP 'A'
#define K_DOWN 'B'
#define K_LEFT 'D'
#define K_RIGHT 'C'
#define K_ABILITY '5'
#define NEXT_TURN ' '
#define SAVE 's'
#define LOAD 'l'
#define NEW 'n'
#define ABILITY_TIMER 5

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