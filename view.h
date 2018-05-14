#ifndef VIEW_H
#define VIEW_H
#include <iostream>
class View{
protected:
    const int rowNum;
    const int columnNum;
public:
    View(int rowNum, int columnNum);
    
    virtual void print(std::ostream &out) const =0;
    virtual void notify(int row, int column, char ch) = 0;
    virtual void setData(const std::string &m) = 0;
    virtual void setHP(int HP) = 0;
    virtual void setGold(int gold) = 0;
    virtual void setFloor(int floor) = 0;
    virtual void setAtk(double Atk) = 0;
    virtual void setDef(double Def) = 0;
    virtual void addAction(const std::string &action) = 0;
    virtual void cleanAction() = 0;
    virtual ~View() = 0;
};

#endif
