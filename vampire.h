#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire: public Player {
public:
    Vampire(Cell *pCell, Game *game);
    void gainHP(int i);
    virtual bool attack(const std::string &d, int atk);
};

#endif
