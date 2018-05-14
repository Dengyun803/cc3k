#include "wd.h"
#include "cell.h"

WD::WD(Cell *pCell, Game *game, Player &p): Potion(pCell, game, p){}

double WD::getDef() const {
    if (getCell()->getType() == "drow") {
        if (p.getDef()-7.5 < 0) return 0;
        return p.getDef()-7.5;
    }
    if (p.getDef()-5<0) return 0;
    return p.getDef()-5;
}

double WD::getAtk() const {return p.getAtk();}

void WD::gainHP(int i) {
    p.gainHP(i);
}
/*
 bool WD::attack(const std::string &d){
	return p.attack(d);
 }
 */

