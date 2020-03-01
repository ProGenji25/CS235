#include "Fighter.h"

Fighter::Fighter(string name, int max_hp, int strength, int speed, int magic)
{
	this->name = name;
	this->max_hp = max_hp;
	this->current_hp = max_hp;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
}

Fighter::~Fighter() {}

string Fighter::getName() const
{
	return name;
}

int Fighter::getMaximumHP() const
{
	return max_hp;
}

int Fighter::getCurrentHP() const
{
	return current_hp;
}

int Fighter::getStrength() const
{
	return strength;
}

int Fighter::getSpeed() const
{
	return speed;
}

int Fighter::getMagic() const
{
	return magic;
}

void Fighter::takeDamage(int damage)
{
	int damage_taken;
	damage_taken = damage - (speed / 4);

	if (damage_taken <= 1)
	{
		current_hp--;
	}
	else if (damage_taken > 1)
	{
		current_hp -= damage_taken;
	}
}
