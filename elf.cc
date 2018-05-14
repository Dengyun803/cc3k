#include "elf.h"
#include "game.h"
#include "cell.h"
#include "player.h"
#include <iostream>
#include <sstream>
Elf::Elf(Cell *pCell, Game *game):Enemy(pCell, game){
    HP = 140;
    Atk = 30;
    Def = 10;
}

Elf::~Elf(){}

bool Elf::attack(){
    bool success = false;
    for (int i = 0; i < 2; i++) {
        int hit = rand()%2;
        Cell *n = pCell->getNeighbour(pCell->checkPlayer());
        if (hit == 0) {
            game->notifyAction("E deals 0 damage to PC(Miss). ");
            success = (success || false);
        } else {
            //		std::cout << pCell->checkPlayer() << std::endl;
            int dDef = (n->getCharacter())->getDef();
            int damage = (int)(ceil((100.0/(dDef+100.0)) * Atk));
            (n->getCharacter())->loseHP(damage);
            std::stringstream ss;
            ss << damage;
            std::string action = "E deals " + ss.str() + " damage to PC. ";
            game->notifyAction(action);
            success = (success || true);
        }
        if (n->getContent() == "drow") {
            break;
        }
    }
    return success;
}

void Elf::die(){
    Cell *n = pCell->getNeighbour(pCell->checkPlayer());
    std::string e = n->getType();
    pCell->setContent(pCell->getOrigin());
    pCell->setType("N");
    game->notifyAction("PC slains E, ");
    if (e == "goblin") {
        game->notifyAction("steals 5 gold from E(+5), ");
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

