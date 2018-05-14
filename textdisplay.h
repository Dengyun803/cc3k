#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <sstream>
#include <string>
#include "view.h"

class TextDisplay: public View{
    char **theDisplay;
    std::string race, action;
    int HP, gold, floor;
    double Atk, Def;
public:
    TextDisplay(int rowNum, int columnNum);
    ~TextDisplay();
    void print(std::ostream &out) const;
    void setData(const std::string &race);
    void setHP(int HP);
    void setGold(int gold);
    void setFloor(int floor);
    void setAtk(double Atk);
    void setDef(double Def);
    void notify(int row, int column, char ch);
    void addAction(const std::string &action);
    void cleanAction();
};

#endif
