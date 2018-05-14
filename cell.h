#ifndef CELL_H
#define CELL_H
#include <string>
#include <iostream>

class Game;
class Character;

const int MAXNEIGHBOURS = 8;

class Cell{
    std::string content;
    std::string type; //indicate type of gold or potion
    std::string origin;
    Character *pContent;
    int numNeighbours;
    Cell *neighbours[MAXNEIGHBOURS];
    int row, column;
    Game *game;
public:
    Cell();
    ~Cell();
    std::string getContent() const;
    std::string getType() const;
    std::string getOrigin() const;
    int getRow() const;
    int getColumn() const;
    Character * getCharacter() const;
    void setContent(const std::string &change);
    void setType(const std::string &change);
    void setOrigin(const std::string &change);
    void setCoords(const int row, const int column);
    void setCharacter(Character * character);
    void setGame(Game * game);
    void addNeighbour(Cell *neighbour, int direction);
    Cell * getNeighbour(int direction);
    void eraseChar();
    int convertDir(const std::string &direction) const;
    std::string getDir(const int direction) const;
    void checkNeighbours() const;// for player finding potion
    int checkPlayer() const;
    void enemyAct();
    void refreshEnemy();
    bool checkDragon() const;
};

#endif
