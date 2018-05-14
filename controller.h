#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "game.h"
#include "view.h"

class Controller: public GameNotification{
	Game *game;
	View *td;
	public:
	Controller();
	~Controller();
	
	void play();
        void testPlay(const std::string &f);
	void restart();
	void notify(int row, int column, char ch);// Notify td
	void notifyHP(int change);
	void notifyGold(int change);
	void notifyAction(const std::string &change);
	void notifyAtk(double change);
	void notifyDef(double change);
 	void notifyFloor(int change);
	void setData(const std::string &race);
};

#endif
