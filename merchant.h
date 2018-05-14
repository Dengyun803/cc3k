#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant: public Enemy{
public:
    Merchant(Cell *pCell, Game *game);
    ~Merchant();
    bool getHostile();
    bool attack();
    void die();
};

#endif
