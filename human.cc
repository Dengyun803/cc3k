#include "human.h"
#include "game.h"
#include "cell.h"
#include "player.h"
#include <iostream>
#include <sstream>
Human::Human(Cell *pCell, Game *game):Enemy(pCell, game){
    HP = 140;
    Atk = 20;
    Def = 20;
}

Human::~Human(){}

bool Human::attack(){
    int hit = rand()%2;
    if (hit == 0) {
        game->notifyAction("H deals 0 damage to PC(Miss). ");
        return false;
    } else {
        //		std::cout << pCell->checkPlayer() << std::endl;
        Cell *n = pCell->getNeighbour(pCell->checkPlayer());
        int dDef = (n->getCharacter())->getDef();
        int damage = (int)(ceil((100.0/(dDef+100.0)) * Atk));
        (n->getCharacter())->loseHP(damage);
        std::stringstream ss;
        ss << damage;
        std::string action = "H deals " + ss.str() + " damage to PC. ";
        game->notifyAction(action);
        return true;
        
    }
    
}

void Human::die(){
    Cell *n = pCell->getNeighbour(pCell->checkPlayer());
    std::string e = n->getType();
    pCell->setContent(pCell->getOrigin());
    pCell->setType("N");
    game->notifyAction("PC slains H, ");
    if (e == "goblin") {
        game->notifyAction("steals 5 gold from H(+5), ");
        game->setPlayerGold(game->getPlayerGold()+5);
    }
    pCell->eraseChar();
    game->notifyAction("and H drops two normal piles of gold");
    pCell->setContent("gold");
    pCell->setType("two normal");
    game->notify(pCell->getRow(), pCell->getColumn(), 'G');
}

