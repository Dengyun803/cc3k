#include "textdisplay.h"

TextDisplay::TextDisplay(int rowNum, int columnNum):View(rowNum, columnNum), race(""), action(""), gold(0), floor(1) {
    theDisplay = new char*[rowNum];
    for (int i=0; i<rowNum; i++) {
        theDisplay[i] = new char[columnNum];
    }
    //first draw the 4 edges
    for (int i=0; i<rowNum; i++){
        theDisplay[i][0] = '|';
        theDisplay[i][columnNum-1] = '|';
    }
    for (int i=1; i<columnNum-1; i++){
        theDisplay[0][i] = '-';
        theDisplay[rowNum-1][i] = '-';
    }
    // fill the map with ' '
    for (int i=1; i<rowNum-1; i++) {
        for (int j=1; j<columnNum-1; j++){
            theDisplay[i][j] = ' ';
        }
    }
    // draw the 5 chambers
    // draw the top-left chamber
    for (int i=2; i<8; i++) {
        theDisplay[i][2] = '|';
        theDisplay[i][29] = '|';
    }
    for (int j=3; j<29; j++) {
        theDisplay[2][j] = '-';
        theDisplay[7][j] = '-';
        for (int i=3; i<7; i++) {
            theDisplay[i][j] = '.';
        }
    }
    // draw the bottom-left chamber
    for (int i=14; i<23; i++) {
        theDisplay[i][3] = '|';
        theDisplay[i][25] = '|';
    }
    for (int j=4; j<25; j++) {
        theDisplay[14][j] = '-';
        theDisplay[22][j] = '-';
        for (int i=15; i<22; i++) {
            theDisplay[i][j] = '.';
        }
    }
    // draw the central chamber
    for (int i=9; i<14; i++) {
        theDisplay[i][37] = '|';
        theDisplay[i][50] = '|';
    }
    for (int j=38; j<50; j++) {
        theDisplay[9][j] = '-';
        theDisplay[13][j] = '-';
        for (int i=10; i<13; i++) {
            theDisplay[i][j] = '.';
        }
    }
    // draw the bottom-right chamber
    for (int i=15; i<23; i++) {theDisplay[i][76] = '|';}
    for (int i=15; i<19; i++) {theDisplay[i][64] = '|';}
    for (int i=18; i<23; i++) {theDisplay[i][36] = '|';}
    for (int j=65; j<76; j++) {theDisplay[15][j] = '-';}
    for (int j=37; j<76; j++) {theDisplay[22][j] = '-';}
    for (int j=37; j<64; j++) {theDisplay[18][j] = '-';}
    for (int j=65; j<76; j++) {
        for (int i=16; i<22; i++) {
            theDisplay[i][j] = '.';
        }
    }
    for (int j=37; j<65; j++) {
        for (int i=19; i<22; i++) {
            theDisplay[i][j] = '.';
        }
    }
    
    // draw the top-right chamber
    
    
    for (int i=39; i<62; i++){
        theDisplay[2][i] = '-';
        for (int j=3; j<7; j++) {
            theDisplay[j][i] = '.';
        }
    }
    for (int j=2; j<8; j++) {theDisplay[j][38] = '|';}
    for (int j=2; j<5; j++) {theDisplay[j][62] = '|';}
    for (int i=63; i<70; i++){theDisplay[4][i] = '-';}
    for (int j=4; j<6; j++) {theDisplay[j][70] = '|';}
    for (int i=71; i<73; i++){theDisplay[5][i] = '-';}
    for (int j=5; j<7; j++) {theDisplay[j][73] = '|';}
    for (int i=74; i<76; i++){theDisplay[6][i] = '-';}
    for (int j=6; j<14; j++) {theDisplay[j][76] = '|';}
    for (int j=7; j<14; j++) {theDisplay[j][60] = '|';}
    for (int i=39; i<60; i++){theDisplay[7][i] = '-';}
    for (int i=61; i<76; i++){theDisplay[13][i] = '-';}
    for (int i=62; i<70; i++){theDisplay[5][i] = '.';}
    for (int i=62; i<73; i++){theDisplay[6][i] = '.';}
    for (int i=61; i<76; i++) {
        for (int j=7; j<13; j++) {
            theDisplay[j][i] = '.';
        }
    }
    // draw the horizontal passages
    for (int i=30; i<38; i++) {theDisplay[4][i] = '#';}
    for (int i=31; i<44; i++) {theDisplay[8][i] = '#';}
    for (int i=13; i<32; i++) {theDisplay[11][i] = '#';}
    for (int i=54; i<60; i++) {theDisplay[11][i] = '#';}
    for (int i=31; i<55; i++) {theDisplay[16][i] = '#';}
    for (int i=26; i<36; i++) {theDisplay[20][i] = '#';}
    // draw the vertical passages
    for (int j=8; j<14; j++) {theDisplay[j][13] = '#';}
    for (int j=8; j<21; j++) {theDisplay[j][31] = '#';}
    for (int j=4; j<9; j++) {theDisplay[j][33] = '#';}
    for (int j=14; j<18; j++) {theDisplay[j][43] = '#';}
    for (int j=11; j<17; j++) {theDisplay[j][54] = '#';}
    theDisplay[14][69] = '#';
    // draw the doors
    theDisplay[4][29] = '+';
    theDisplay[4][38] = '+';
    theDisplay[7][13] = '+';
    theDisplay[7][43] = '+';
    theDisplay[9][43] = '+';
    theDisplay[11][60] = '+';
    theDisplay[13][43] = '+';
    theDisplay[13][69] = '+';
    theDisplay[14][13] = '+';
    theDisplay[15][69] = '+';
    theDisplay[18][43] = '+';
    theDisplay[20][25] = '+';
    theDisplay[20][36] = '+';
    
}

TextDisplay::~TextDisplay(){
    if (theDisplay) {
        for (int i=0; i<rowNum; i++) {
            if (theDisplay[i]) delete[] theDisplay[i];
        }
        delete[] theDisplay;
    }
}

void TextDisplay::setData(const std::string &race){
    if (race == "shade") {
        this->race = "shade";
        HP = 125;
        Atk = 25;
        Def = 25;
    } else if (race == "drow") {
        this->race = "drow";
        HP = 150;
        Atk = 25;
        Def = 15;
    } else if (race == "vampire") {
        this->race = "vampire";
        HP = 50;
        Atk = 25;
        Def = 25;
    } else if (race == "troll") {
        this->race = "troll";
        HP = 120;
        Atk = 25;
        Def = 15;
    } else if (race == "goblin") {
        this->race = "goblin";
        HP = 110;
        Atk = 15;
        Def = 20;
    }
}

void TextDisplay::setHP(int HP){
    this->HP = HP;
}

void TextDisplay::setGold(int gold){
    this->gold = gold;
}

void TextDisplay::setFloor(int floor){
    this->floor = floor;
}

void TextDisplay::setAtk(double Atk){
    this->Atk = Atk;
}

void TextDisplay::setDef(double Def){
    this->Def = Def;
}

void TextDisplay::notify(int row, int column, char ch){
    theDisplay[row][column] = ch;
}

void TextDisplay::addAction(const std::string &action){
    this->action += action;
}

void TextDisplay::cleanAction(){
	action = "";
}

void TextDisplay::print(std::ostream &out) const{
    for (int i=0; i<rowNum; i++) {
        for (int j=0; j<columnNum; j++) {
            out << theDisplay[i][j];
        }
        out << std::endl;
    }
    out << "Race: " << race << " Gold: " << gold;
    for (int i=0; i<50; i++) { out << " "; }
    out << "Floor " << floor << std::endl;
    out << "HP: " << HP << std::endl;
    out << "Atk: " << Atk << std::endl;
    out << "Def: " << Def << std::endl;
    out << "Action: " << action << std::endl;
}


