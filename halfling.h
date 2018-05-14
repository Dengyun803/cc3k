#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

class Halfling: public Enemy{
public:
    Halfling(Cell *pCell, Game *game);
    ~Halfling();
    bool attack();
    void die();
};

#endif
