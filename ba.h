#ifndef BA_H
#define BA_H

#include "potion.h"

class BA : public Potion {
public:
    BA(Cell *pCell, Game *game, Player &p);
    double getAtk() const;
    double getDef() const;
    void gainHP(int i);
    //    virtual bool attack(const std::string &d);
    //	virtual bool move(const std::string &direction);
};

#endif
