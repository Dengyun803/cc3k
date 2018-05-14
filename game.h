#ifndef GAME_H
#define GAME_H
#include "cell.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
class Player;

class GameNotification{
public:
    virtual void notify(int row, int column, char ch) = 0;
    virtual void notifyHP(int change) = 0;
    virtual void notifyGold(int change) = 0;
    virtual void notifyAction(const std::string &change) = 0;
    virtual void notifyAtk(double change) = 0;
    virtual void notifyDef(double change) = 0;
    virtual void notifyFloor(int change) = 0;
    virtual void setData(const std::string &race) = 0;
};

class Game{
    Cell ***theGrid;
    int rowNum, columnNum, playerHP, playerGold;
    GameNotification *notification;
    Player *p;
    int point;
    int floor;
    bool win;
    bool die;
    bool hostile;
public:
    Game();
    void clearGame();
    void changeCell(int l, int i, int j, char c);
    void setAllContent();
    Player *getPlayer();
    void setPlayerHP(int change);
    void setPlayerGold(int change);
    void setPoint(int change);
    void setFloor(int change);
    void setDie(bool change);
    int getPlayerHP() const;
    int getPlayerGold() const;
    int getPoint() const;
    bool getDie() const;
    void init(int row, int column, GameNotification *gameNotification);
    bool move(const std::string &m);
    bool attack(const std::string &d);
    void createPC(const std::string &race);
    bool isWon() const;
    void notify(int row, int column, char ch); // Tell GameNotification to chance the textdisplay
    void notifyHP(int change);
    void notifyGold(int change);
    void notifyAtk(double change);
    void notifyDef(double change);
    void notifyFloor(int change);
    void notifyAction(const std::string &change);
    bool usePotion(const std::string &d);
    void knowPotion(const std::string &p);
    void useTempPotion(const std::string &p);
    void enemiesAct();
    bool addGold(Cell *gp, const std::string &type);
    bool addPotion(Cell *pp, const std::string &type);
    bool addEnemy(Cell *ep, const std::string &type);
    std::string generateEnemy() const;
    std::string generatePotion() const;
    std::string generateGold() const;
    Cell *generateRCell(int f, int chamber) const;
    void generateAll();
    bool getHostile() const;
    void setHostile(bool change);
    void refreshFloor();
    void upStairs();
    void addPC(const std::string &race);
    ~Game();
};

#endif
