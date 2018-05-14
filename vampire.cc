#include "vampire.h"
#include "game.h"
Vampire::Vampire(Cell *pCell, Game *game): Player(pCell,game) {
    HP = 50;
    Atk = 25;
    Def = 15;
}

void Vampire::gainHP(int i) {
    HP += i;
    game->setPlayerHP(HP);
}

bool Vampire::attack(const std::string &d, int atk) {
    int direction = pCell->convertDir(d);
    Cell * c = pCell->getNeighbour(direction);
    if (c == NULL) {
        return false;
    } else {
        std::string s = c->getContent();
        if (s == "enemy") {
            int hit = rand()%2;
            int dDef = (c->getCharacter())->getDef();
            int damage = (int)(ceil((100.0/(dDef+100.0)) * atk));
            if (c->getType() == "halfling" && hit == 0) {
                game->notifyAction("PC deals 0 damage to H(Miss). ");
                (c->getCharacter())->loseHP(0);
            } else {
		if (c->getType() == "merchant" && game->getHostile() == false) game->setHostile(true);
                std::stringstream ss;
                std::string action;
                ss << damage;
                if (c->getType() == "dwarf") {
                    gainHP(-5);
                    action = "PC is allergic to D and loses 5 HP. PC deals " + ss.str() + " damage to " + c->getType();
                } else {
                    gainHP(5);
                    action = "PC attacks successfully and gains 5 HP. PC deals " + ss.str() + " damage to " + c->getType();
                }
                game->notifyAction(action);
                (c->getCharacter())->loseHP(damage);
            }
            return true;
        } else {
            return false;
        }
    }
}


