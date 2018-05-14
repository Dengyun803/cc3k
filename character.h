#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <cstdlib>
class Cell;
class Game;
class Character{
protected:
    int HP;
    double Atk;
    double Def;
    Cell *pCell;
    Game *game;
public:
    Character(Cell *pCell, Game *game);
    virtual ~Character() = 0;
    virtual int getHP() const;
    virtual double getAtk() const;
    virtual double getDef() const;
    virtual Cell *getCell() const;
    virtual void setHP(int h);
    virtual void setCell(Cell * change);
    void basicMove(int i);
    virtual void notify(Cell *c);
    char transToSymbol(const std::string &s);
    virtual void loseHP(int i);
    virtual void act(); //only used in Enemy class;
    virtual void refresh(); //only used in Enemy class;
};

#endif
