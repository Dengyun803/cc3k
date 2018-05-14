#include "wa.h"
#include "cell.h"

WA::WA(Cell *pCell, Game *game, Player &p): Potion(pCell, game, p){}

double WA::getAtk() const {
    if (getCell()->getType() == "drow") {
        if (p.getAtk()-7.5 < 0) return 0;
        return p.getAtk()-7.5;
    }
    if (p.getAtk()-5 < 0) return 0;
    return p.getAtk()-5;
}

double WA::getDef() const{return p.getDef();}

void WA::gainHP(int i) {
    p.gainHP(i);
}
/*
 bool WA::attack(const std::string &d){
 return p.attack(d);
 }
 */
//bool move(const std::string &direction){
//        p.move(direction);
//}

