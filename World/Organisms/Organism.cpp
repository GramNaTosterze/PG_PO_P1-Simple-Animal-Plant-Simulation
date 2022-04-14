
#include "Organism.h"

Organism::Organism(): strength(0), initiative(0), position({0,0}), world(nullptr), symbol('_') {}
Organism::Organism(unsigned int strength, int initiative, Pos position, Canvas* canvas, char symbol): strength(strength), initiative(initiative), position(position), world(canvas), symbol(symbol) {}
Organism::~Organism() {}
