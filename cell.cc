#include "cell.h"
#include "game.h"
#include "character.h"

//ctor
Cell::Cell():content("N"), type("N"), origin("N"), pContent(NULL), numNeighbours(0), row(0), column(0), game(NULL) {
    for (int i=0; i<8; i++) {
        neighbours[i] = NULL;
    }
}

//delete the pointer to character
void Cell::eraseChar(){
    if (pContent) delete pContent;
    pContent = NULL;
    game->notify(row, column, '.');
}

//dtor
Cell::~Cell(){}

std::string Cell::getContent() const {
    return content;
}

std::string Cell::getOrigin() const {
    return origin;
}

std::string Cell::getType() const {
    return type;
}

Character * Cell::getCharacter() const {
    return pContent;
}

int Cell::getRow() const {
    return row;
}

int Cell::getColumn() const {
    return column;
}

void Cell::setContent(const std::string &change) {
    content = change;
}

void Cell::setType(const std::string &change) {
    type = change;
}

void Cell::setOrigin(const std::string &change) {
    origin = change;
}

void Cell::setCoords(const int row, const int column) {
    this->row = row;
    this->column = column;
}

void Cell::setCharacter(Character * character) {
    this->pContent = character;
}

void Cell::setGame(Game * game) {
    this->game = game;
}

void Cell::addNeighbour(Cell *neighbour, int direction) {
    if (numNeighbours < MAXNEIGHBOURS) {
        neighbours[direction] = neighbour;
        numNeighbours += 1;
    }
}

Cell * Cell::getNeighbour(int direction) {
    return neighbours[direction];
}

int Cell::convertDir(const std::string &direction) const{
    if (direction == "nw") {return 0;}
    else if (direction == "no") {return 1;}
    else if (direction == "ne") {return 2;}
    else if (direction == "we") {return 3;}
    else if (direction == "ea") {return 4;}
    else if (direction == "sw") {return 5;}
    else if (direction == "so") {return 6;}
    else if (direction == "se") {return 7;}
    else {return -1;}
}

std::string Cell::getDir(const int direction) const {
    if (direction == 0) {return "Northwest";}
    else if (direction == 1) {return "North";}
    else if (direction == 2) {return "Northeast";}
    else if (direction == 3) {return "West";}
    else if (direction == 4) {return "East";}
    else if (direction == 5) {return "Southwest";}
    else if (direction == 6) {return "South";}
    else if (direction == 7) {return "Southeast";}
    else {return "invalid direction";}
}

void Cell::checkNeighbours() const {
    std::string act;
    for (int i=0; i < MAXNEIGHBOURS; i++) {
        if (neighbours[i]){
            if (neighbours[i]->getContent() == "unknown potion") {
                act = "PC sees an unknown potion at " + getDir(i) + ". ";
                
            } else if (neighbours[i]->getContent() == "potion") {
                act = "PC sees a " + neighbours[i]->getType() + " potion at " + getDir(i) + ". ";
            } else {
                continue;
            }
            game->notifyAction(act);
        }
    }
}

int Cell::checkPlayer() const {
    int gold = -1;
    for (int i=0; i < MAXNEIGHBOURS; i++) {
        if (neighbours[i]){
            if ((neighbours[i])->getContent() == "player" || (neighbours[i])->getContent() == "player & dragon hoard") {
                //				std::cout << i << std::endl;
                return i;
            }
            if (type == "dragon" && (neighbours[i])->getType() == "dragon hoard") gold = i;
        }
    }
    if (gold != -1) {
        Cell *g = neighbours[gold];
        for (int i=0; i < MAXNEIGHBOURS; i++) {
            if (g->getNeighbour(i)){
                if (g->getNeighbour(i)->getContent() == "player") {
                    //				std::cout << i << std::endl;
                    return i;
                }
            }
        }
    }

    return -1;
}

void Cell::enemyAct() {
    if (pContent) pContent->act();
}

void Cell::refreshEnemy(){
    if (pContent) pContent->refresh();
}

bool Cell::checkDragon() const {
    for (int i=0; i < MAXNEIGHBOURS; i++) {
        if (neighbours[i]){
            if ((neighbours[i])->getType() == "dragon") {
                return true;
            }
        }
    }
    return false;
}
