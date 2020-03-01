#pragma once
#include "Fighter.h"

class Robot : public Fighter
{
public:
	Robot(string name, int max_hp, int strength, int speed, int magic);
	~Robot();

	int getDamage();
	bool useAbility();
	void reset();
	void regenerate();

protected:
	int damage;
	int current_energy;
	int max_energy;
	int bonus_damage;

};