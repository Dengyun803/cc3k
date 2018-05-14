#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
class Enemy: public Character{
	protected:
	bool acted;
	public:
	Enemy(Cell *pCell, Game *game);
	virtual ~Enemy() = 0;
	void move();
    void act();
	void refresh();
	virtual bool attack() = 0;
	void loseHP(int i);
	virtual void die() = 0;
};

#endif
