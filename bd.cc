#include "bd.h"
#include "cell.h"

BD::BD(Cell *pCell, Game *game, Player &p): Potion(pCell, game, p){}

double BD::getDef() const {
    if (getCell()->getType() == "drow") {
        return p.getDef()+7.5;
    }
    return p.getDef()+5;
}

double BD::getAtk() const {return p.getAtk();}

void BD::gainHP(int i) {
    p.gainHP(i);
}
/*
 bool BD::attack(const std::string &d){
 return p.attack(d);
 }
 */


