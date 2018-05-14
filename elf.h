#ifndef ELF_H
#define ELF_H
#include "enemy.h"

class Elf: public Enemy{
public:
    Elf(Cell *pCell, Game *game);
    ~Elf();
    bool attack();
    void die();
};

#endif
