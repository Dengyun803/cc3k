#ifndef BD_H
#define BD_H

#include "potion.h"

class BD : public Potion {
public:
    BD(Cell *pCell, Game *game, Player &p);
    double getDef() const;
    double getAtk() const;
    void gainHP(int i);
    //    virtual bool attack(const std::string &d);
    //	virtual bool move(const std::string &direction);
};

#endif
