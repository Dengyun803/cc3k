#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Dragon: public Enemy{
public:
    Dragon(Cell *pCell, Game *game);
    ~Dragon();
    bool attack();
    void die();
};

#endif
