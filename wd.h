#ifndef WD_H
#define WD_H

#include "potion.h"

class WD : public Potion {
public:
    WD(Cell *pCell, Game *game, Player &p);
    double getDef() const;
    double getAtk() const;
    void gainHP(int i);
    //    virtual bool attack(const std::string &d);
    //	virtual bool move(const std::string &direction);
};

#endif 
