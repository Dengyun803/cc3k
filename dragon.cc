#include "dragon.h"
#include "game.h"
#include "cell.h"
#include "player.h"
#include <iostream>
#include <sstream>
Dragon::Dragon(Cell *pCell, Game *game):Enemy(pCell, game){
    HP = 150;
    Atk = 20;
    Def = 20;
}

Dragon::~Dragon(){}

bool Dragon::attack(){
    int hit = rand()%2;
    if (hit == 0) {
        game->notifyAction("D deals 0 damage to PC(Miss). ");
        return false;
    } else {
        //		std::cout << pCell->checkPlayer() << std::endl;
        int dDef = game->getPlayer()->getDef();
        int damage = (int)(ceil((100.0/(dDef+100.0)) * Atk));
        game->getPlayer()->loseHP(damage);
        std::stringstream ss;
        ss << damage;
        std::string action = "D deals " + ss.str() + " damage to PC. ";
        game->notifyAction(action);
        return true;
    }
    
}

void Dragon::die(){
    Cell *n = game->getPlayer()->getCell();
    std::string e = n->getType();
    pCell->setContent(pCell->getOrigin());
    pCell->setType("N");
    game->notifyAction("PC slains D, ");
    if (e == "goblin") {
        game->notifyAction("steals 5 gold from D(+5), ");
        game->setPlayerGold(game->getPlayerGold()+5);
    }
    game->notifyAction("PC can pick up the dragon hoard now");
    pCell->eraseChar();
}

