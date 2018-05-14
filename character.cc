#include "character.h"
#include "cell.h"
#include "game.h"
Character::Character(Cell *pCell, Game *game):pCell(pCell), game(game){}

Character::~Character(){}

int Character::getHP() const {
    return HP;
}

double Character::getAtk() const {
    return Atk;
}

double Character::getDef() const {
    return Def;
}

Cell *Character::getCell() const {
	return pCell;
}

void Character::setCell(Cell * change) {
    pCell = change;
}

char Character::transToSymbol(const std::string &s) {
    if (s == "doorway") return '+';
    if (s == "passage") return '#';
    if (s == "floor tile") return '.';
    if (s == "player" || s == "player & dragon hoard") return '@';
    if (s == "gold") return 'G';
    if (s == "dwarf") return 'W';
    if (s == "human") return 'H';
    if (s == "elf") return 'E';
    if (s == "goblin") return 'G';
    if (s == "halfling") return 'L';
    if (s == "orc") return 'O';
    if (s == "merchant") return 'M';
    if (s == "dragon") return 'D';
    return '0';
}

void Character::notify(Cell *pCell){
    std::string s = pCell->getContent();
    char c;
    if (s != "enemy") {
	c = transToSymbol(pCell->getContent());
    } else {
	c = transToSymbol(pCell->getType());	
    }
    game->notify(pCell->getRow(), pCell->getColumn(), c);
}

void Character::basicMove(int i){
    Cell * c = getCell()->getNeighbour(i);
    c->setCharacter(this); //let the new cell points to the character
    if (getCell()->getContent() == "player && dragon hoard") {
        c->setContent("player"); //set the content to character
    } else if (c->getType() == "dragon hoard") {
        c->setContent("player & dragon hoard");
    } else {
        c->setContent(getCell()->getContent());
    }
    c->setType(getCell()->getType());
    getCell()->setCharacter(NULL); //delete the original cell's pointer to player
    if (getCell()->getContent() == "player & dragon hoard" && (getCell()->checkDragon())) {
        getCell()->setContent("gold");
        getCell()->setType("dragon hoard");
    } else if (getCell()->getContent() == "player & dragon hoard" && !(getCell()->checkDragon())) {
        getCell()->setContent(getCell()->getOrigin());
        getCell()->setType("N");
    } else {
        getCell()->setContent(getCell()->getOrigin());
        getCell()->setType("N");
    }

    notify(getCell());
    setCell(c);
    notify(getCell());
}

void Character::act(){
	std::cout << "foo" << std::endl;
}

void Character::refresh(){
	std::cout << "foo" << std::endl;
}

void Character::loseHP(int i) {
	std::cout << "foo" << std::endl;
}

void Character::setHP(int h){
	HP = h;
}
