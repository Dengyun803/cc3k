#include "game.h"
#include "player.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "potion.h"
#include "ba.h"
#include "bd.h"
#include "wa.h"
#include "wd.h"
#include "dwarf.h"
#include "human.h"
#include "elf.h"
#include "orc.h"
#include "halfling.h"
#include "merchant.h"
#include "dragon.h"

Game::Game(): theGrid(NULL), playerGold(0), notification(NULL), win(false), die(true), hostile(false) {}

void Game::setAllContent() {
  for (int l=0; l<5; l++){
    //first draw the 4 edges
    for (int i=0; i<rowNum; i++){
        (theGrid[l][i][0]).setContent("wall");
        (theGrid[l][i][columnNum-1]).setContent("wall");
    }
    for (int i=1; i<columnNum-1; i++){
        (theGrid[l][0][i]).setContent("wall");
        (theGrid[l][rowNum-1][i]).setContent("wall");
    }
    // fill the map with ' '
    for (int i=1; i<rowNum-1; i++) {
        for (int j=1; j<columnNum-1; j++){
            (theGrid[l][i][j]).setContent("empty");
        }
    }
    // draw the 5 chambers
    // draw the top-left chamber
    for (int i=2; i<8; i++) {
        (theGrid[l][i][2]).setContent("wall");
        (theGrid[l][i][29]).setContent("wall");
    }
    for (int j=3; j<29; j++) {
        (theGrid[l][2][j]).setContent("wall");
        (theGrid[l][7][j]).setContent("wall");
        for (int i=3; i<7; i++) {
            (theGrid[l][i][j]).setContent("floor tile");
        }
    }
    // draw the bottom-left chamber
    for (int i=14; i<23; i++) {
        (theGrid[l][i][3]).setContent("wall");
        (theGrid[l][i][25]).setContent("wall");
    }
    for (int j=4; j<25; j++) {
        (theGrid[l][14][j]).setContent("wall");
        (theGrid[l][22][j]).setContent("wall");
        for (int i=15; i<22; i++) {
            (theGrid[l][i][j]).setContent("floor tile");
        }
    }
    // draw the central chamber
    for (int i=9; i<14; i++) {
        (theGrid[l][i][37]).setContent("wall");
        (theGrid[l][i][50]).setContent("wall");
    }
    for (int j=38; j<50; j++) {
        (theGrid[l][9][j]).setContent("wall");
        (theGrid[l][13][j]).setContent("wall");
        for (int i=10; i<13; i++) {
            (theGrid[l][i][j]).setContent("floor tile");
        }
    }
    // draw the bottom-right chamber
    for (int i=15; i<23; i++) {(theGrid[l][i][76]).setContent("wall");}
    for (int i=15; i<19; i++) {(theGrid[l][i][64]).setContent("wall");}
    for (int i=18; i<23; i++) {(theGrid[l][i][36]).setContent("wall");}
    for (int j=65; j<76; j++) {(theGrid[l][15][j]).setContent("wall");}
    for (int j=37; j<76; j++) {(theGrid[l][22][j]).setContent("wall");}
    for (int j=37; j<64; j++) {(theGrid[l][18][j]).setContent("wall");}
    for (int j=65; j<76; j++) {
        for (int i=16; i<22; i++) {
            (theGrid[l][i][j]).setContent("floor tile");
        }
    }
    for (int j=37; j<65; j++) {
        for (int i=19; i<22; i++) {
            (theGrid[l][i][j]).setContent("floor tile");
        }
    }
    
    // draw the top-right chamber
    
    
    for (int i=39; i<62; i++){
        (theGrid[l][2][i]).setContent("wall");
        for (int j=3; j<7; j++) {
            (theGrid[l][j][i]).setContent("floor tile");
        }
    }
    for (int j=2; j<8; j++) {(theGrid[l][j][38]).setContent("wall");}
    for (int j=2; j<5; j++) {(theGrid[l][j][62]).setContent("wall");}
    for (int i=63; i<70; i++){(theGrid[l][4][i]).setContent("wall");}
    for (int j=4; j<6; j++) {(theGrid[l][j][70]).setContent("wall");}
    for (int i=71; i<73; i++){(theGrid[l][5][i]).setContent("wall");}
    for (int j=5; j<7; j++) {(theGrid[l][j][73]).setContent("wall");}
    for (int i=74; i<76; i++){(theGrid[l][6][i]).setContent("wall");}
    for (int j=6; j<14; j++) {(theGrid[l][j][76]).setContent("wall");}
    for (int j=7; j<14; j++) {(theGrid[l][j][60]).setContent("wall");}
    for (int i=39; i<60; i++){(theGrid[l][7][i]).setContent("wall");}
    for (int i=61; i<76; i++){(theGrid[l][13][i]).setContent("wall");}
    for (int i=62; i<70; i++){(theGrid[l][5][i]).setContent("floor tile");}
    for (int i=62; i<73; i++){(theGrid[l][6][i]).setContent("floor tile");}
    for (int i=61; i<76; i++) {
        for (int j=7; j<13; j++) {
            (theGrid[l][j][i]).setContent("floor tile");
        }
    }
    // draw the horizontal passages
    for (int i=30; i<38; i++) {(theGrid[l][4][i]).setContent("passage");}
    for (int i=31; i<44; i++) {(theGrid[l][8][i]).setContent("passage");}
    for (int i=13; i<32; i++) {(theGrid[l][11][i]).setContent("passage");}
    for (int i=54; i<60; i++) {(theGrid[l][11][i]).setContent("passage");}
    for (int i=31; i<55; i++) {(theGrid[l][16][i]).setContent("passage");}
    for (int i=26; i<36; i++) {(theGrid[l][20][i]).setContent("passage");}
    // draw the vertical passages
    for (int j=8; j<14; j++) {(theGrid[l][j][13]).setContent("passage");}
    for (int j=8; j<21; j++) {(theGrid[l][j][31]).setContent("passage");}
    for (int j=4; j<9; j++) {(theGrid[l][j][33]).setContent("passage");}
    for (int j=14; j<18; j++) {(theGrid[l][j][43]).setContent("passage");}
    for (int j=11; j<17; j++) {(theGrid[l][j][54]).setContent("passage");}
    (theGrid[l][14][69]).setContent("passage");
    // draw the doors
    (theGrid[l][4][29]).setContent("doorway");
    (theGrid[l][4][38]).setContent("doorway");
    (theGrid[l][7][13]).setContent("doorway");
    (theGrid[l][7][43]).setContent("doorway");
    (theGrid[l][9][43]).setContent("doorway");
    (theGrid[l][11][60]).setContent("doorway");
    (theGrid[l][13][43]).setContent("doorway");
    (theGrid[l][13][69]).setContent("doorway");
    (theGrid[l][14][13]).setContent("doorway");
    (theGrid[l][15][69]).setContent("doorway");
    (theGrid[l][18][43]).setContent("doorway");
    (theGrid[l][20][25]).setContent("doorway");
    (theGrid[l][20][36]).setContent("doorway");
    
    //set all prev equal to the original content of the cell
    for (int i=0; i<25; i++) {
        for (int j=0; j<79; j++) {
            theGrid[l][i][j].setOrigin(theGrid[l][i][j].getContent());
        }
    }
  }
}

void Game::init(int row, int column, GameNotification *gameNotification){
    if (theGrid) clearGame();
    rowNum = row;
    columnNum = column;
    floor = 0;
    win = false;
    die = false;
    notification = gameNotification;
    theGrid = new Cell**[5];
  for (int l=0; l<5; l++){
    theGrid[l] = new Cell*[rowNum];
    for (int i=0; i<rowNum; ++i) {
        theGrid[l][i] = new Cell[columnNum];
    }
  }
  for (int l=0; l<5; l++){
    for (int i=0; i<rowNum; ++i) {
        for (int j=0; j<columnNum;++j) {
            (theGrid[l][i][j]).setGame(this);
            (theGrid[l][i][j]).setCoords(i, j);
        }
    }
  }
  for (int l=0; l<5; l++){
    for (int i=0; i<rowNum; ++i) {
        for (int j=0; j<columnNum;++j) {
            if (i != 0 && j != 0) (theGrid[l][i][j]).addNeighbour(&(theGrid[l][i-1][j-1]), 0);
            if (i != 0) (theGrid[l][i][j]).addNeighbour(&(theGrid[l][i-1][j]), 1);
            if (i != 0 && j != column-1) (theGrid[l][i][j]).addNeighbour(&(theGrid[l][i-1][j+1]), 2);
            if (j != 0) (theGrid[l][i][j]).addNeighbour(&(theGrid[l][i][j-1]), 3);
            if (j != column-1) (theGrid[l][i][j]).addNeighbour(&(theGrid[l][i][j+1]), 4);
            if (i != row-1 && j != 0) (theGrid[l][i][j]).addNeighbour(&(theGrid[l][i+1][j-1]), 5);
            if (i != row-1) (theGrid[l][i][j]).addNeighbour(&(theGrid[l][i+1][j]), 6);
            if (i != row-1 && j != column-1)(theGrid[l][i][j]).addNeighbour(&(theGrid[l][i+1][j+1]), 7);
        }
    }
  }
  setAllContent();
}

void Game::notifyHP(int change) {
    notification->notifyHP(change);
}

void Game::notifyGold(int change) {
    notification->notifyGold(change);
}

void Game::setPlayerHP(int change) {
    playerHP = change;
    notifyHP(change);
}

void Game::setPlayerGold(int change) {
    playerGold = change;
    setPoint(change);
    notifyGold(change);
}

void Game::setFloor(int change){
    floor = change;
    if (floor == 5) win = true;
    notifyFloor(change+1);
}

void Game::setDie(bool change){
	die = change;
}

void Game::setPoint(int change) {
    point = change;
}

int Game::getPlayerHP() const{
    return playerHP;
}

int Game::getPlayerGold() const{
    return playerGold;
}

int Game::getPoint() const{
    return point;
}

bool Game::getDie() const{
	return die;
}

void Game::notify(int row, int column, char ch) {
    notification->notify(row, column, ch);
}

void Game::clearGame(){
    if (theGrid) {
      for (int l=0; l<5; l++){
        if (theGrid[l]) {
          for (int i=0; i<rowNum; ++i) {
            if (theGrid[l][i]){
		for (int j=0; j<columnNum; ++j) {
			(theGrid[l][i][j]).eraseChar();
		}
                delete[] theGrid[l][i];
                theGrid[l][i] = NULL;
            }
          }
          delete[] theGrid[l];
          theGrid[l] = NULL;
        }
      }
      delete[] theGrid;
      theGrid = NULL;
    }
    p = NULL;
    win = false;
}

void Game::notifyAction(const std::string &change) {
    notification->notifyAction(change);
}

void Game::createPC(const std::string &race){
    int chamber = rand()%5;
    Cell *pl = generateRCell(floor, chamber);
    while (pl->getContent() != "floor tile"){
      chamber = rand()%5;
      pl = generateRCell(floor, chamber);
    }
    if (race == "shade") {
        p = new Shade(pl, this);
        playerHP = 125;
    } else if (race == "drow") {
        p = new Drow(pl, this);
        playerHP = 150;
    } else if (race == "vampire") {
        p = new Vampire(pl, this);
        playerHP = 50;
    } else if (race == "troll") {
        p = new Troll(pl, this);
        playerHP = 120;
    } else if (race == "goblin") {
        p = new Goblin(pl, this);
        playerHP = 110;
    } else {}
    notify(pl->getRow(), pl->getColumn(), '@');
    pl->setContent("player");
    pl->setType(race);
    pl->setCharacter(p);
//    notifyAction("Player character has spawned. ");
    int g = rand()%5;
    while (g == chamber) {
        g= rand()%5;
    }
    Cell *sp = generateRCell(floor, g);
    while (sp->getContent() != "floor tile"){
      sp = generateRCell(floor, g);
    }
    sp->setContent("stairs");
    notify(sp->getRow(), sp->getColumn(), '\\');
}

void Game::addPC(const std::string &race){
    Cell *pl;
    for (int l=0; l<5; l++){
	for (int i=0; i<25; i++){
            for (int j=0; j<79; j++){
		if ((theGrid[l][i][j]).getContent() == "player") {
		    pl = &(theGrid[l][i][j]);
		    break;
		}
	    }
	}
    }
    if (race == "shade") {
        p = new Shade(pl, this);
        playerHP = 125;
    } else if (race == "drow") {
        p = new Drow(pl, this);
        playerHP = 150;
    } else if (race == "vampire") {
        p = new Vampire(pl, this);
        playerHP = 50;
    } else if (race == "troll") {
        p = new Troll(pl, this);
        playerHP = 120;
    } else if (race == "goblin") {
        p = new Goblin(pl, this);
        playerHP = 110;
    } else {}
    pl->setType(race);
    pl->setCharacter(p);
}

Game::~Game(){
    clearGame();
    notification = NULL;
}

bool Game::move(const std::string &m){
    return p->move(m);
}

bool Game::usePotion(const std::string &d){
    return p->usePotion(d);
}

bool Game::isWon() const{
	return win;
}

void Game::knowPotion(const std::string &p){
    for (int l=0; l<5; l++){
	for (int i=0; i<rowNum; i++){
		for (int j=0; j<columnNum; j++){
			if ((theGrid[l][i][j]).getType() == p) (theGrid[l][i][j]).setContent("potion");
		}
	}
    }
}

void Game::useTempPotion(const std::string &p){
    if (p == "BA") {
        this->p = new BA((this->p)->getCell(), this, *(this->p));
        notifyAtk((this->p)->getAtk());
    } else if (p == "BD") {
        this->p = new BD((this->p)->getCell(), this, *(this->p));
        notifyDef((this->p)->getDef());
    } else if (p == "WA") {
        this->p = new WA((this->p)->getCell(), this, *(this->p));
        notifyAtk((this->p)->getAtk());
    } else if (p == "WD") {
        this->p = new WD((this->p)->getCell(), this, *(this->p));
        notifyDef((this->p)->getDef());
    } else { std::cout << "invalid potion" << std::endl; }
}

void Game::notifyAtk(double change){
	notification->notifyAtk(change);
}

void Game::notifyDef(double change){
        notification->notifyDef(change);
}

void Game::notifyFloor(int change){
	notification->notifyFloor(change);
}

void Game::enemiesAct(){
      for (int l=0; l<5; l++){
	for (int i=0; i<rowNum; i++) {
          for (int j=0; j<columnNum; j++) {
		if ((theGrid[l][i][j]).getContent() == "enemy") {
			(theGrid[l][i][j]).refreshEnemy();
		}
	  }
	}
      }
      for (int l=0; l<5; l++){
	for (int i=0; i<rowNum; i++) {
		for (int j=0; j<columnNum; j++) {
	//		std::cout << i << " " << j << std::endl;
			if ((theGrid[l][i][j]).getContent() == "enemy") {
				(theGrid[l][i][j]).enemyAct();
			}
		}
	}
      }
}

Player *Game::getPlayer(){
	return p;
}

bool Game::attack(const std::string &d) {
    return p->attack(d, p->getAtk());
}

bool Game::addGold(Cell *gp, const std::string &type) {
    if (gp->getContent() != "floor tile") return false;
    gp->setContent("gold");
    gp->setType(type);
    notify(gp->getRow(), gp->getColumn(), 'G');
    if (type == "dragon hoard") {
        int g = rand()%8;
        while (gp->getNeighbour(g)->getContent() != "floor tile") {
            g = rand()%8;
        }
        Cell *n = gp->getNeighbour(g);
        return addEnemy(n, "dragon");
    }
    return true;
}

bool Game::addPotion(Cell *pp, const std::string &type) {
    if (pp->getContent() != "floor tile") return false;
    pp->setContent("unknown potion");
    pp->setType(type);
    return true;
}

bool Game::addEnemy(Cell *ep, const std::string &type){
    if (ep->getContent() != "floor tile") return false;
    ep->setContent("enemy");
    ep->setType(type);
    if (type == "dwarf") {
        Enemy *e = new Dwarf(ep, this);
        ep->setCharacter(e);
    } else if (type == "human") {
        Enemy *e = new Human(ep, this);
        ep->setCharacter(e);
    } else if (type == "elf") {
        Enemy *e = new Elf(ep, this);
        ep->setCharacter(e);
    } else if (type == "orc") {
        Enemy *e = new Orc(ep, this);
        ep->setCharacter(e);
    } else if (type == "halfling") {
        Enemy *e = new Halfling(ep, this);
        ep->setCharacter(e);
    } else if (type == "merchant") {
        Enemy *e = new Merchant(ep, this);
        ep->setCharacter(e);
    } else if (type == "dragon") {
        Enemy *e = new Dragon(ep, this);
        ep->setCharacter(e);
        notify(ep->getRow(), ep->getColumn(), 'D');
    } else {}
    return true;
}


std::string Game::generateEnemy() const{
    int e = rand()%18;
    std::string enemy;
    if ( e >= 0 && e < 4) {
        enemy = "human";
    } else if ( e >= 4 && e < 7) {
        enemy = "dwarf";
    } else if ( e >= 7 && e < 12) {
        enemy = "halfling";
    } else if ( e >= 12 && e < 14) {
        enemy = "elf";
    } else if ( e >= 14 && e < 16) {
        enemy = "orc";
    } else if ( e >= 16 && e < 18) {
        enemy = "merchant";
    } else { enemy = ""; }
    return enemy;
}

std::string Game::generateGold() const{
    int g = rand()%8;
    std::string goldType;
    if ( g >= 0 && g < 5) {
        goldType = "normal";
    } else if ( g >= 5 && g < 7) {
        goldType = "small";
    } else if ( g == 7 ) {
        goldType = "dragon hoard";
    } else { goldType = ""; }
    return goldType;
}

std::string Game::generatePotion() const{
    int p = rand()%6;
    std::string potion;
    if (p == 0) {
        potion = "RH";
    } else if (p == 1) {
        potion = "PH";
    } else if (p == 2) {
        potion = "BA";
    } else if (p == 3) {
        potion = "WA";
    } else if (p == 4) {
        potion = "BD";
    } else if (p == 5) {
        potion = "WD";
    } else { potion = ""; }
    return potion;
}

Cell *Game::generateRCell(int f, int chamber) const{
    int column;
    int row;
    if (chamber == 0) {
        row = rand()%4 + 3;
	column = rand()%26 + 3;
    } else if (chamber == 1) {
        row = rand()%10 + 3;
        if (row <= 4) column = rand()%23 + 39;
        if (row == 5) column = rand()%31 + 39;
        if (row == 6) column = rand()%34 + 39;
        if (row > 6) column = rand()%15 + 61;
    } else if (chamber == 2) {
        row = rand()%3 + 10;
        column = rand()%12 + 38;
    } else if (chamber == 3) {
        row = rand()%7 + 15;
        column = rand()%21 + 4;
    } else {
        row = rand()%6 + 16;
        if (row <= 18) column = rand()%12 + 65;
        if (row > 18) column = rand()%40 + 37;
    }
    return (&(theGrid[f][row][column]));
}

void Game::generateAll() {
  for (int l=0; l<5; l++){
    for (int i=0;i<10;i++) {
        while (true) {
            if (addPotion(generateRCell(l,rand()%5), generatePotion())) break;
        }
    }
    for (int i=0;i<10;i++) {
        while (true) {
            if (addGold(generateRCell(l,rand()%5), generateGold())) break;
        }
    }
    for (int i=0;i<20;i++) {
        while (true) {
            if (addEnemy(generateRCell(l,rand()%5), generateEnemy())) break;
        }
    }
  }
}

bool Game::getHostile() const {
    return hostile;
}

void Game::setHostile(bool change) {
    hostile = change;
}

void Game::refreshFloor(){
    for (int i=0; i<rowNum; i++){
      for (int j=0; j<columnNum; j++){
        if ((theGrid[floor][i][j]).getContent() == "floor tile") notify(i, j, '.');
        if ((theGrid[floor][i][j]).getContent() == "player") notify(i, j, '@');
        if ((theGrid[floor][i][j]).getContent() == "potion") notify(i, j, 'P');
        if ((theGrid[floor][i][j]).getContent() == "unknown potion") notify(i, j, 'P');
        if ((theGrid[floor][i][j]).getContent() == "gold") notify(i, j, 'G');
        if ((theGrid[floor][i][j]).getContent() == "stairs") notify(i, j, '\\');
        if ((theGrid[floor][i][j]).getContent() == "enemy"){
          if ((theGrid[floor][i][j]).getType() == "human") notify(i, j, 'H');
          if ((theGrid[floor][i][j]).getType() == "dwarf") notify(i, j, 'W');
          if ((theGrid[floor][i][j]).getType() == "halfling") notify(i, j, 'L');
          if ((theGrid[floor][i][j]).getType() == "elf") notify(i, j, 'E');
          if ((theGrid[floor][i][j]).getType() == "orc") notify(i, j, 'O');
          if ((theGrid[floor][i][j]).getType() == "merchant") notify(i, j, 'M');
          if ((theGrid[floor][i][j]).getType() == "dragon") notify(i, j, 'D');
        }

      }
    }
}

void Game::upStairs(){
   setFloor(floor+1);
   if (floor == 5) return;
   std::string race = (p->getCell())->getType();
   int tempHP = playerHP;
   (p->getCell())->eraseChar();
   createPC(race);
   notification->setData(race);
   setPlayerHP(tempHP);
   notifyAction("PC goes up stairs");
}

void Game::changeCell(int l, int i, int j, char c){
   if (c=='H') {
	(theGrid[l][i][j]).setContent("enemy");
	(theGrid[l][i][j]).setType("human");
        (theGrid[l][i][j]).setCharacter(new Human((&(theGrid[l][i][j])), this));
   } else if (c == 'W') {
        (theGrid[l][i][j]).setContent("enemy");
        (theGrid[l][i][j]).setType("dwarf");
        (theGrid[l][i][j]).setCharacter(new Dwarf((&(theGrid[l][i][j])), this));
   } else if (c == 'E') {
        (theGrid[l][i][j]).setContent("enemy");
        (theGrid[l][i][j]).setType("elf");
	(theGrid[l][i][j]).setCharacter(new Elf((&(theGrid[l][i][j])), this));
   } else if (c == 'O') {
        (theGrid[l][i][j]).setContent("enemy");
        (theGrid[l][i][j]).setType("orc");
        (theGrid[l][i][j]).setCharacter(new Orc((&(theGrid[l][i][j])), this));
   } else if (c == 'M') {
        (theGrid[l][i][j]).setContent("enemy");
        (theGrid[l][i][j]).setType("merchant");
	(theGrid[l][i][j]).setCharacter(new Merchant((&(theGrid[l][i][j])), this));
   } else if (c == 'D') {
        (theGrid[l][i][j]).setContent("enemy");
        (theGrid[l][i][j]).setType("dragon");
	(theGrid[l][i][j]).setCharacter(new Dragon((&(theGrid[l][i][j])), this));
   } else if (c == 'L') {
        (theGrid[l][i][j]).setContent("enemy");
        (theGrid[l][i][j]).setType("halfling");
        (theGrid[l][i][j]).setCharacter(new Halfling((&(theGrid[l][i][j])), this));
   } else if (c == '0') {
        (theGrid[l][i][j]).setContent("unknown potion");
        (theGrid[l][i][j]).setType("RH");
   } else if (c == '1') {
        (theGrid[l][i][j]).setContent("unknown potion");
        (theGrid[l][i][j]).setType("BA");
   } else if (c == '2') {
        (theGrid[l][i][j]).setContent("unknown potion");
        (theGrid[l][i][j]).setType("BD");
   } else if (c == '3') {
        (theGrid[l][i][j]).setContent("unknown potion");
        (theGrid[l][i][j]).setType("PH");
   } else if (c == '4') {
        (theGrid[l][i][j]).setContent("unknown potion");
        (theGrid[l][i][j]).setType("WA");
   } else if (c == '5') {
        (theGrid[l][i][j]).setContent("unknown potion");
        (theGrid[l][i][j]).setType("WD");
   } else if (c == '6') {
        (theGrid[l][i][j]).setContent("gold");
        (theGrid[l][i][j]).setType("normal");
   } else if (c == '7') {
        (theGrid[l][i][j]).setContent("gold");
        (theGrid[l][i][j]).setType("small");
   } else if (c == '8') {
        (theGrid[l][i][j]).setContent("gold");
        (theGrid[l][i][j]).setType("merchant hoard");
   } else if (c == '9') {
        (theGrid[l][i][j]).setContent("gold");
        (theGrid[l][i][j]).setType("dragon hoard");
   } else if (c == '@') {
        (theGrid[l][i][j]).setContent("player");
   } else {}
}
