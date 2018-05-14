#include "ba.h"
#include "cell.h"

BA::BA(Cell *pCell, Game *game, Player &p) : Potion(pCell, game, p) {}

double BA::getAtk() const {
    if (getCell()->getType() == "drow") {
        return p.getAtk()+7.5;
    }
    return p.getAtk()+5;
}

double BA::getDef() const {return p.getDef();}

void BA::gainHP(int i) {
    p.gainHP(i);
}
/*
 bool BA::attack(const std::string &d){
	return p.attack(d);
 }
 */


