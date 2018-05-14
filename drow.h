#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow: public Player {
public:
    Drow(Cell *pCell, Game *game);
    void gainHP(int i);
    virtual bool attack(const std::string &d, int atk);
};

#endif
