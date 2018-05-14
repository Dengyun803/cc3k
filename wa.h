#ifndef WA_H
#define WA_H

#include "potion.h"

class WA : public Potion {
public:
    WA(Cell *pCell, Game *game, Player &p);
    double getAtk() const;
    double getDef() const;
    void gainHP(int i);
    //    virtual bool attack(const std::string &d);
    //    virtual bool move(const std::string &direction);
};

#endif
