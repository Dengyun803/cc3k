#include "shade.h"
#include "game.h"
Shade::Shade(Cell *pCell, Game *game): Player(pCell,game) {
    HP = 125;
    Atk = 25;
    Def = 25;
}

void Shade::gainHP(int i) {
    HP += i;
    if (HP > 125) HP = 125;
    game->setPlayerHP(HP);
}

bool Shade::attack(const std::string &d, int atk) {
    int direction = pCell->convertDir(d);
    Cell * c = getCell()->getNeighbour(direction);
    if (c == NULL) {
        return false;
    } else {
        std::string s = c->getContent();
        if (s == "enemy") {
            int hit = rand()%2;
            int dDef = (c->getCharacter())->getDef();
            int damage = (int)(ceil((100.0/(dDef+100.0)) * atk));
            //				std::cout << atk << std::endl;
            if (c->getType() == "halfling" && hit == 0) {
                game->notifyAction("PC deals 0 damage to H(Miss). ");
                (c->getCharacter())->loseHP(0);
            } else {
		if (c->getType() == "merchant" && game->getHostile() == false) game->setHostile(true);
                std::stringstream ss;
                ss << damage;
                std::string action = "PC deals " + ss.str() + " damage to " + c->getType();
                game->notifyAction(action);
                (c->getCharacter())->loseHP(damage);
            }
            return true;
        } else {
            return false;
        }
    }
}


