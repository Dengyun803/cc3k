#ifndef POTION_H
#define POTION_H
#include "player.h"

class Potion: public Player{
protected:
    Player &p;
public:
    Potion(Cell *pCell, Game *game, Player &p);
    virtual ~Potion();
    virtual bool attack(const std::string &d, int atk);
    virtual void setHP(int h);
    virtual int getHP() const;
    virtual Cell *getCell() const;
    virtual void setCell(Cell * change);
    virtual void notify(Cell *c);
    virtual void loseHP(int i);
    
};

#endif
