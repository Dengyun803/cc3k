#ifndef ORC_H
#define ORC_H
#include "enemy.h"

class Orc: public Enemy{
public:
    Orc(Cell *pCell, Game *game);
    ~Orc();
    bool attack();
    void die();
};

#endif
