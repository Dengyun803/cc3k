#ifndef SHADE_H
#define SHADE_H
#include "player.h"

class Shade: public Player {
public:
    Shade(Cell *pCell, Game *game);
    void gainHP(int i);
    virtual bool attack(const std::string &d, int atk);
};

#endif
