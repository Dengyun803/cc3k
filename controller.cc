#include "controller.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "textdisplay.h"
#include "game.h"

Controller::Controller(): td(NULL){
	game = new Game;
}

Controller::~Controller(){
	if (game) delete game;
	if (td) delete td;
}

void Controller::notifyHP(int change){
	td->setHP(change);
}

void Controller::notifyGold(int change){
        td->setGold(change);
}

void Controller::notifyAction(const std::string &change){
	td->addAction(change);
}

void Controller::play(){
//	std::cout << "We now can only print the map, press P to show it" << std::endl;
	std::cout << "We now have a PC, enter g to get start!" << std::endl;
	char command;
	srand(time(NULL));
	while (std::cin >> command){
		if (command == 'q') return;
		if (command == 'g') {
		    if (td) delete td;
                        td = new TextDisplay(25, 79);
			game->init(25, 79, this);
                        game->generateAll();
                        game->refreshFloor();
			while (true) {
				std::cout << "Choose a race, we have (s)hade, (d)row, (v)ampire, (t)roll and (g)oblin" << std::endl;
				char race;
				std::cin >> race;
				if (race == 'q') return;
				if (race == 's') {
					game->createPC("shade");
					td->setData("shade");
					td->print(std::cout);
					td->cleanAction();
					break;
                                } else if (race == 'd') {
                                        game->createPC("drow");
//                                        game->generateAll();
                                        td->setData("drow");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else if (race == 'v') {
                                        game->createPC("vampire");
//                                        game->generateAll();
                                        td->setData("vampire");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else if (race == 't') {
                                        game->createPC("troll");
//                                        game->generateAll();
                                        td->setData("troll");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else if (race == 'g') {
                                        game->createPC("goblin");
//                                        game->generateAll();
                                        td->setData("goblin");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else {
					std::cout << "Invalid input, please choose a race again" << std::endl;
				}
			}
			break;
		} else {
			std::cout << "Invalid input" << std::endl;
		}
	}
	while ( game->getDie() == false && game->isWon() == false ) {
		std::cout << "Your turn, please enter the command:" << std::endl;
		std::string s;
		while (std::cin >> s) {
			if (s == "q") return;
			if (s == "r") {
				restart();
				return;
			}
			if (s=="no" || s=="so" || s=="ea" || s=="we" || s=="ne" || s=="nw" || s=="se" || s=="sw") {
				if (game->move(s)) {
					break;
				} else {
					std::cout << "Invalid move, please enter again" << std::endl;
				}
			} else if (s=="u"){
				std::cin >> s;
				if (s=="q") return;
				if (s=="no" || s=="so" || s=="ea" || s=="we" || s=="ne" || s=="nw" || s=="se" || s=="sw") {
					if (game->usePotion(s)){
						break;
					} else {
						std::cout << "No potion there" << std::endl;
					}
				} else {
					std::cout << "Invalid command, please enter again" << std::endl;
				}
			} else if (s=="a") {
				std::cin >> s;
                if (s=="q") return;
				if (s=="no" || s=="so" || s=="ea" || s=="we" || s=="ne" || s=="nw" || s=="se" || s=="sw") {
					if (game->attack(s)){
						break;
					} else {
						std::cout << "No enemy there" << std::endl;
					}
				} else {
                         std::cout << "Invalid command, please enter again" << std::endl;
                }
			} else {
				std::cout << "Invalid command, please enter again" << std::endl;
			}
		}
        if (game->getDie()) break;
        if (game->isWon()) break;
		std::cout << "Enemies' turn, please wait..." << std::endl;
		game->enemiesAct();
                game->refreshFloor();
		td->print(std::cout);
		td->cleanAction();
	}
	if (game->getDie()) {
		std::cout << "GAME OVER" << std::endl;
		std::cout << "r for a new game, q for quit" << std::endl;
		char c;
		while (std::cin >> c) {
			if (c == 'r') {
				restart();
				return;
			} else if (c == 'q') {
				return;
			} else {
				std::cout << "Invalid command, please enter again" << std::endl;
			}
		}
	}
        if (game->isWon()) {
		std::cout << "YOU WIN!" << std::endl;
		std::cout << "Your final mark is " << game->getPlayerGold() << std::endl;
		std::cout << "r for a new game, q for quit" << std::endl;
                char c;
                while (std::cin >> c) {
                        if (c == 'r') {
                                restart();
                                return;
                        } else if (c == 'q') {
                                return;
                        } else {
                                std::cout << "Invalid command, please enter again" << std::endl;
                        }
                }
        }
}

void Controller::testPlay(const std::string &f){
	std::cout << "Load Mode" << std::endl;
        srand(time(NULL));
        if (td) delete td;
        td = new TextDisplay(25, 79);
        game->init(25, 79, this);
        std::ifstream file(f.c_str());
        char c;
	for (int l=0; l<5; l++) {
		for(int i=0; i<25; i++) {
			for (int j=0; j<80; j++) {
				file >> std::noskipws >> c;
				game->changeCell(l, i, j, c);
			}
		}
	}
	
        game->refreshFloor();
	
/*        while (std::cin >> command){
                if (command == 'q') return;
                if (command == 'g') {
                    if (td) delete td;
                        td = new TextDisplay(25, 79);
                        game->init(25, 79, this);
                        game->generateAll();
                        game->refreshFloor();
*/                        while (true) {
                                std::cout << "Choose a race, we have (s)hade, (d)row, (v)ampire, (t)roll and (g)oblin" << std::endl;
                                char race;
                                std::cin >> race;
                                if (race == 'q') return;
                                if (race == 's') {
                                        game->addPC("shade");
                                        td->setData("shade");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else if (race == 'd') {
                                        game->addPC("drow");
//                                        game->generateAll();
                                        td->setData("drow");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else if (race == 'v') {
                                        game->addPC("vampire");
//                                        game->generateAll();
                                        td->setData("vampire");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else if (race == 't') {
                                        game->addPC("troll");
//                                        game->generateAll();
                                        td->setData("troll");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else if (race == 'g') {
                                        game->addPC("goblin");
//                                        game->generateAll();
                                        td->setData("goblin");
                                        td->print(std::cout);
                                        td->cleanAction();
                                        break;
                                } else {
                                        std::cout << "Invalid input, please choose a race again" << std::endl;
                                }
                        }
        

        while ( game->getDie() == false && game->isWon() == false ) {
                std::cout << "Your turn, please enter the command:" << std::endl;
                std::string s;
                while (std::cin >> s) {
                        if (s == "q") return;
                        if (s == "r") {
                                restart();
                                return;
                        }
                        if (s=="no" || s=="so" || s=="ea" || s=="we" || s=="ne" || s=="nw" || s=="se" || s=="sw") {
                                if (game->move(s)) {
                                        break;
                                } else {
                                        std::cout << "Invalid move, please enter again" << std::endl;
                                }
                        } else if (s=="u"){
                                std::cin >> s;
                                if (s=="q") return;
                                if (s=="no" || s=="so" || s=="ea" || s=="we" || s=="ne" || s=="nw" || s=="se" || s=="sw") {
                                        if (game->usePotion(s)){
                                                break;
                                        } else {
                                                std::cout << "No potion there" << std::endl;
                                        }
                                } else {
                                        std::cout << "Invalid command, please enter again" << std::endl;
                                }
                        } else if (s=="a") {
                                std::cin >> s;
                if (s=="q") return;
                                if (s=="no" || s=="so" || s=="ea" || s=="we" || s=="ne" || s=="nw" || s=="se" || s=="sw") {
                                        if (game->attack(s)){
                                                break;
                                        } else {
                                                std::cout << "No enemy there" << std::endl;
                                        }
                                } else {
                         std::cout << "Invalid command, please enter again" << std::endl;
                }
                        } else {
                                std::cout << "Invalid command, please enter again" << std::endl;
                        }
                }
        if (game->getDie()) break;
        if (game->isWon()) break;
                std::cout << "Enemies' turn, please wait..." << std::endl;
                game->enemiesAct();
                game->refreshFloor();
                td->print(std::cout);
                td->cleanAction();
        }
        if (game->getDie()) {
                std::cout << "GAME OVER" << std::endl;
                std::cout << "r for a new game, q for quit" << std::endl;
                char c;
                while (std::cin >> c) {
                        if (c == 'r') {
                                restart();
                                return;
                        } else if (c == 'q') {
                                return;
                        } else {
                                std::cout << "Invalid command, please enter again" << std::endl;
                        }
                }
        }
        if (game->isWon()) {
                std::cout << "YOU WIN!" << std::endl;
                std::cout << "Your final mark is " << game->getPlayerGold() << std::endl;
                std::cout << "r for a new game, q for quit" << std::endl;
                char c;
                while (std::cin >> c) {
                        if (c == 'r') {
                                restart();
                                return;
                        } else if (c == 'q') {
                                return;
                        } else {
                                std::cout << "Invalid command, please enter again" << std::endl;
                        }
                }
        }
}

void Controller::notify(int row, int column, char ch){
	td->notify(row, column, ch);
}

void Controller::restart(){
	if (game) delete game;
 	if (td) delete td;
	td = NULL;
	game = new Game;
	play();
}

void Controller::notifyAtk(double change){
	td->setAtk(change);
}

void Controller::notifyDef(double change){
        td->setDef(change);
}

void Controller::notifyFloor(int change){
	td->setFloor(change);
}

void Controller::setData(const std::string &race){
	td->setData(race);
}
