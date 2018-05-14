#include "player.h"
#include "cell.h"
#include "game.h"

Player::Player(Cell *pCell, Game *game): Character(pCell, game){}

Game * Player::getGame() const{
    return game;
}

Player::~Player(){}

//return true if make a success move, reture false otherwise
bool Player::move(const std::string &direction) {
    setHP(game->getPlayerHP());
    int d = pCell->convertDir(direction);
    Cell * c = getCell()->getNeighbour(d);
    if (c == NULL) {
        return false;
    } else {
        std::string s = c->getContent();
        if (s == "wall" || s == "empty" || s == "enemy" || s == "potion" || s == "unknown potion") {
            return false;
        } else if (s == "stairs") {
            game->upStairs();
            return true;
          }
        else if (s == "gold") {
            std::string g = c->getType();
            if (getCell()->getType() == "troll") {
                gainHP(5);
                game->notifyAction("PC regains 5 HP. ");
            }
            if (g == "small") {
                game->setPlayerGold(1+game->getPlayerGold());
                game->notifyAction("PC picks up a small gold(+1). ");
            } else if (g == "normal") {
                game->setPlayerGold(2+game->getPlayerGold());
                game->notifyAction("PC picks up a normal gold(+2). ");
            } else if (g == "two normal") {
                game->setPlayerGold(4+game->getPlayerGold());
                game->notifyAction("PC picks up two normal gold(+4). ");
            } else if (g == "merchant hoard") {
                game->setPlayerGold(4+game->getPlayerGold());
                game->notifyAction("PC picks up a merchant hoard(+4). ");
            } else if (g == "dragon hoard" && !(getCell()->checkDragon())) {
                game->setPlayerGold(6+game->getPlayerGold());
                game->notifyAction("PC picks up a dragon hoard(+6). ");
            } else if (g == "dragon hoard" && getCell()->checkDragon()) {
                game->notifyAction("Dragon is not dead. PC cannot pick up the dragon hoard. ");
            } else {}
        } else if (s == "doorway" || s == "passage" || s == "floor tile") {
            if (getCell()->getType() == "troll") {
                gainHP(5);
                game->notifyAction("PC regains 5 HP. ");
            }
            std::string action = "PC moves " + c->getDir(d) + ". ";
            game->notifyAction(action);
        } else { return false;}
        basicMove(d);
        getCell()->checkNeighbours();
        return true;
    }

           
}

bool Player::usePotion(const std::string &d) {
    int direction = pCell->convertDir(d);
    Cell * c = (getCell())->getNeighbour(direction);
    if (c == NULL) {
        return false;
    } else {
        std::string s = c->getContent();
        if (s == "potion" || s == "unknown potion"){
            if (getCell()->getType() == "troll") {
                gainHP(5);
                game->notifyAction("PC regains 5 HP. ");
            }
            std::string t = c->getType();
            std::string act;
            if (t == "RH") {
                if (getCell()->getType() == "drow") {
                    act = "PC uses restore health potion(HP+15). ";
                    gainHP(15);
                }
                else {
                    act = "PC uses restore health potion(HP+10). ";
                    gainHP(10);
                }
            } else if (t == "PH") {
                if (getCell()->getType() == "drow") {
                    act = "PC uses poison health potion(HP-15). ";
                    loseHP(15);
                } else {
                    act = "PC uses poison health potion(HP-10). ";
                    loseHP(10);
                }
            } else if (t == "BA") {
                act = "PC uses Boost Atk potion(Atk+5). ";
                if (getCell()->getType() == "drow") act = "PC uses Boost Atk potion(Atk+7.5). ";
                game->useTempPotion("BA");
            } else if (t == "BD") {
                act = "PC uses Boost Def potion(Def+5). ";
                if (getCell()->getType() == "drow") act = "PC uses Boost Def potion(Def+7.5). ";
                game->useTempPotion("BD");
            } else if (t == "WA") {
                act = "PC uses Wound Atk potion(Atk-5). ";
                if (getCell()->getType() == "drow") act = "PC uses Wound Atk potion(Atk-7.5). ";
                game->useTempPotion("WA");
            } else if (t == "WD") {
                act = "PC uses Wound Def potion(Def-5). ";
                if (getCell()->getType() == "drow") act = "PC uses Wound Def potion(Def-7.5). ";
                game->useTempPotion("WD");
            } else {}
            getCell()->setCharacter(game->getPlayer());
            c->setContent(c->getOrigin());
            c->setType("N");
            notify(c);
            game->notifyAction(act);
            if (s == "unknown potion") game->knowPotion(t);
            (getCell())->checkNeighbours();
            return true;
        } else {
            return false;
        }
    }
}

void Player::loseHP(int i){
    HP -= i;
    if (HP <= 0) {
        HP =0;
        game->setDie(true); 
        game->notifyAction("PC died. ");
    }
    game->setPlayerHP(HP);
}

bool Player::attack(const std::string &d, int atk) {
    return false;
}

