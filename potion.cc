#include "potion.h"

Potion::Potion(Cell *pCell, Game *game, Player &p):Player(pCell, game), p(p){
    HP = p.getHP();
    Atk = p.getAtk();
    Def = p.getDef();
}

Potion::~Potion(){ delete &p; }

bool Potion::attack(const std::string &d, int atk){
    return p.attack(d, atk);
}
/*
 bool Potion::move(const std::string &direction){
	return p.move(direction);
 }
 */

void Potion::setHP(int h) {
    p.setHP(h);
}

int Potion::getHP() const{
    return p.getHP();
}

Cell *Potion::getCell() const {
    return p.getCell();
}

void Potion::setCell(Cell * change){
    return p.setCell(change);
}

void Potion::notify(Cell *c){
    return p.notify(c);
}

void Potion::loseHP(int i){
    return p.loseHP(i);
}

