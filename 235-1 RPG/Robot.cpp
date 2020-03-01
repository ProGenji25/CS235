#include "Robot.h"

Robot::Robot(std::string name, int max_hp, int strength, int speed, int magic) : Fighter(name, max_hp, strength, speed, magic)
{
	max_energy = 2 * magic;
	current_energy = max_energy;
	bonus_damage = 0;
}

Robot::~Robot() {}

int Robot::getDamage()
{
	int result = strength + bonus_damage;
	return result;
}

void Robot::reset()
{
	current_hp = max_hp;
	current_energy = max_energy;
	bonus_damage = 0;
}

void Robot::regenerate()
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

bool Robot::useAbility()
{
	bonus_damage = 0;
	double buff = 0.0;
	if (current_energy >= ROBOT_ABILITY_COST)
	{
		buff = (double(strength) * pow((double(current_energy) / double(max_energy)), 4.0));
		bonus_damage = int(buff);
		current_energy -= ROBOT_ABILITY_COST;
		return true;
	}
	else if (current_energy <= ROBOT_ABILITY_COST) { return false; }

}