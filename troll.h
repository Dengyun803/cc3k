#ifndef TROLL_H
#define TROLL_H
#include "player.h"

class Troll: public Player {
public:
    Troll(Cell *pCell, Game *game);
    void gainHP(int i);
    virtual bool attack(const std::string &d, int atk);
};

#endif
