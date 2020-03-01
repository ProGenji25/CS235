#pragma once
#include "Fighter.h"

class Cleric : public Fighter
{
public:
	Cleric(string name, int max_hp, int strength, int speed, int magic);
	~Cleric();

	int getDamage();
	bool useAbility();
	void reset();
	void regenerate();

protected:
	int damage;
	int current_mana;
	int max_mana;

};