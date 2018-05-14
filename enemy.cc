#include "enemy.h"
#include "cell.h"
#include "game.h"
#include <iostream>
#include <string>
#include <sstream>

Enemy::Enemy(Cell *pCell, Game *game):Character(pCell, game), acted(false){};

Enemy::~Enemy(){}

void Enemy::move(){
	int target;
	Cell *c;
	bool full = true;
	for (int i=0; i<8; i++) {
		c = pCell->getNeighbour(i);
		if (c && c->getContent()=="floor tile") full = false;
	}
	while (!full) {
		target = rand()%8;
		c = pCell->getNeighbour(target);
		if (c && c->getContent()=="floor tile") {
			basicMove(target);
			break;
		}
		
	}
}

void Enemy::loseHP(int i){
	HP-=i;
	if (HP <= 0) HP = 0;
	std::stringstream ss;
	ss << HP;
	std::string act = "(" + ss.str() + " HP). ";
	game->notifyAction(act);
	if (HP == 0) die();
}

void Enemy::act(){
    if (acted == false){
        if (getCell()->getType() == "dragon" && getCell()->checkPlayer() != -1) {
            attack();
        } else if (getCell()->getType() != "dragon") {
			if (getCell()->checkPlayer() == -1) {
				move();
            } else if (getCell()->getType() == "merchant" && !game->getHostile()) {
                move();
            } else {
				attack();
			}
        } else {}
		acted = true;
	}

}

void Enemy::refresh(){
	acted = false;
}

