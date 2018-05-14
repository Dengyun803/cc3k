#include "orc.h"
#include "game.h"
#include "cell.h"
#include "player.h"
#include <iostream>
#include <sstream>
Orc::Orc(Cell *pCell, Game *game):Enemy(pCell, game){
    HP = 180;
    Atk = 30;
    Def = 25;
}

Orc::~Orc(){}

bool Orc::attack(){
    int hit = rand()%2;
    if (hit == 0) {
        game->notifyAction("O deals 0 damage to PC(Miss). ");
        return false;
    } else {
        //		std::cout << pCell->checkPlayer() << std::endl;
        Cell *n = pCell->getNeighbour(pCell->checkPlayer());
        int dDef = (n->getCharacter())->getDef();
        int damage = (int)(ceil((100.0/(dDef+100.0)) * Atk));
        if (n->getType() == "goblin") {
            damage = (int)ceil((100.0/(dDef+100.0)) * Atk * 1.5);
        }
        (n->getCharacter())->loseHP(damage);
        std::stringstream ss;
        ss << damage;
        std::string action = "O deals " + ss.str() + " damage to PC. ";
        game->notifyAction(action);
        return true;
        
    }
    
}

void Orc::die(){
    Cell *n = pCell->getNeighbour(pCell->checkPlayer());
    std::string e = n->getType();
    pCell->setContent(pCell->getOrigin());
    pCell->setType("N");
    game->notifyAction("PC slains O, ");
    if (e == "goblin") {
        game->notifyAction("steals 5 gold from O(+5), ");
        game->setPlayerGold(game->getPlayerGold()+5);
    }
    int g = rand()%2;
    if (g == 0) {
        game->notifyAction("and get a small pile of gold(+1)");
        game->setPlayerGold(game->getPlayerGold()+1);
    } else {
        game->notifyAction("and get a normal pile of gold(+2)");
        game->setPlayerGold(game->getPlayerGold()+2);
    }
    pCell->eraseChar();
}

