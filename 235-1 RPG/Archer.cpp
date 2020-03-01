#include "Archer.h"

Archer::Archer(std::string name, int max_hp, int strength, int speed, int magic) : Fighter(name, max_hp, strength, speed, magic)
{
	base_speed = speed;
}

Archer::~Archer() {}

int Archer::getDamage()
{
	return speed;
}

void Archer::reset()
{
	current_hp = max_hp;
	speed = base_speed;
}

void Archer::regenerate()
{
	int hp_regen = strength / 6;

	if (hp_regen <= 1 && current_hp < max_hp)
	{
		current_hp++;
	}
	else if (hp_regen > 1)
	{
		if (current_hp + hp_regen < max_hp)
		{
			current_hp += hp_regen;
		}
		else if (current_hp + hp_regen >= max_hp)
		{
			current_hp = max_hp;
		}
	}
}

bool Archer::useAbility()
{
	speed++;
	return true;
}