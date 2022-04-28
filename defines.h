#pragma once

#define EMPTY_POS {-1,-1}
#define ARROWS 27
#define ESC 27
#define K_UP 'A'
#define K_DOWN 'B'
#define K_LEFT 'D'
#define K_RIGHT 'C'
#define K_ABILITY '5'
#define NEXT_TURN ' '
#define SAVE 's'
#define LOAD 'l'
#define NEW 'n'
#define BACK 'b'
#define ABILITY_TIMER 5

enum {
    HUMAN = 'H',
    WOLF = 'W',
    SHEEP = 'S',
    FOX = 'F',
    TURTLE = 'T',
    ANTELOPE = 'A',
    CYBER_SHEEP = '$',

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
enum TYPE {
    ANIMAL,
    PLANT,
};