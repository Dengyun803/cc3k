#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "character.h"

class Player: public Character {
public:
    Player(Cell *pCell, Game *game);
    Game * getGame() const;
    virtual ~Player() = 0;
    virtual bool move(const std::string &direction);
    bool usePotion(const std::string &d);
    virtual void gainHP(int i) = 0;
    void loseHP(int i);
    virtual bool attack(const std::string &d, int atk);
};

#endif
