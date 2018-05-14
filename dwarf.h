#ifndef DWARF_H
#define DWARF_H
#include "enemy.h"

class Dwarf: public Enemy{
public:
    Dwarf(Cell *pCell, Game *game);
    ~Dwarf();
    bool attack();
    void die();
};

#endif
