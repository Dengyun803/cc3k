#ifndef GOBLIN_H
#define GOBLIN_H
#include "player.h"

class Goblin: public Player {
public:
    Goblin(Cell *pCell, Game *game);
    void gainHP(int i);
    virtual bool attack(const std::string &d, int atk);
};

#endif
