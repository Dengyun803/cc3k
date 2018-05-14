#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human: public Enemy{
public:
    Human(Cell *pCell, Game *game);
    ~Human();
    bool attack();
    void die();
};

#endif
