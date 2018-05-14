#include "troll.h"
#include "game.h"
Troll::Troll(Cell *pCell, Game *game): Player(pCell,game) {
    HP = 120;
    Atk = 25;
    Def = 15;
}

void Troll::gainHP(int i) {
    HP += i;
    if (HP > 120) HP = 120;
    game->setPlayerHP(HP);
}

bool Troll::attack(const std::string &d, int atk) {
    int direction = pCell->convertDir(d);
    Cell * c = pCell->getNeighbour(direction);
    if (c == NULL) {
        return false;
    } else {
        std::string s = c->getContent();
        if (s == "enemy") {
            gainHP(5);
            game->notifyAction("PC regains 5 HP. ");
            int hit = rand()%2;
            int dDef = (c->getCharacter())->getDef();
            int damage = (int)(ceil((100.0/(dDef+100.0)) * atk));
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


