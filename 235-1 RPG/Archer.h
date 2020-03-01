#pragma once
#include "Fighter.h"

class Archer : public Fighter
{
public:
	Archer(string name, int max_hp, int strength, int speed, int magic);
	~Archer();

	int getDamage();
	bool useAbility();
	void reset();
	void regenerate();
	
protected:
	int damage;
	int base_speed;

};