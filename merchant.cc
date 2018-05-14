#include "merchant.h"
#include "game.h"
#include "cell.h"
#include "player.h"
#include <iostream>
#include <sstream>
Merchant::Merchant(Cell *pCell, Game *game):Enemy(pCell, game){
    HP = 30;
    Atk = 70;
    Def = 5;
}

Merchant::~Merchant(){}

bool Merchant::attack(){
    int hit = rand()%2;
    if (hit == 0) {
        game->notifyAction("M deals 0 damage to PC(Miss). ");
        return false;
    } else {
        //		std::cout << pCell->checkPlayer() << std::endl;
        Cell *n = pCell->getNeighbour(pCell->checkPlayer());
        int dDef = (n->getCharacter())->getDef();
        int damage = (int)(ceil((100.0/(dDef+100.0)) * Atk));
        (n->getCharacter())->loseHP(damage);
        std::stringstream ss;
        ss << damage;
        std::string action = "M deals " + ss.str() + " damage to PC. ";
        game->notifyAction(action);
        return true;
    }
    
}

void Merchant::die(){
    Cell *n = pCell->getNeighbour(pCell->checkPlayer());
    std::string e = n->getType();
    pCell->setContent(pCell->getOrigin());
    pCell->setType("N");
    game->notifyAction("PC slains M, ");
    if (e == "goblin") {
        game->notifyAction("steals 5 gold from O(+5), ");
        game->setPlayerGold(game->getPlayerGold()+5);
    }
    pCell->eraseChar();
    game->notifyAction("and M drops a merchant hoard");
    pCell->setContent("gold");
    pCell->setType("merchant hoard");
    game->notify(pCell->getRow(), pCell->getColumn(), 'G');
}

