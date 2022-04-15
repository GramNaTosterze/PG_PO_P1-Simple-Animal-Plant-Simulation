
#include "Organism.h"

Organism::Organism(): strength(0), position({0,0}), world(nullptr), symbol('_') {}
Organism::Organism(unsigned int strength, Pos position, Canvas* canvas, char symbol): strength(strength), position(position), world(canvas), symbol(symbol) {}
Organism::~Organism() {}
