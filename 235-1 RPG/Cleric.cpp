# include "Cleric.h"

Cleric::Cleric(std::string name, int max_hp, int strength, int speed, int magic) : Fighter(name, max_hp, strength, speed, magic)
{
	max_mana = 5 * magic;
	current_mana = max_mana;
}

Cleric::~Cleric() {}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	current_hp = max_hp;
	current_mana = max_mana;
}

void Cleric::regenerate()
{
	int hp_regen = strength / 6;
	if (hp_regen <= 1)
	{
		if (current_hp < max_hp)
		{
			current_hp++;
		}
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

	int mana_regen = magic / 5;
	if (mana_regen <= 1)
	{
		if (current_mana < max_mana)
		{
			current_mana++;
		}
	}
	else if (mana_regen > 1)
	{
		if (current_mana + mana_regen < max_mana)
		{
			current_mana += mana_regen;
		}
		else if (current_mana + mana_regen >= max_mana)
		{
			current_mana = max_mana;
		}
	}
}

bool Cleric::useAbility()
{
	if (current_mana >= CLERIC_ABILITY_COST)
	{
		int heal = magic / 3;
		if (heal <= 1 && current_hp < max_hp)
		{
			current_hp++;
		}
		else if (heal > 1)
		{
			if (current_hp + heal < max_hp)
			{
				current_hp +=heal;
			}
			else if (current_hp + heal >= max_hp)
			{
				current_hp = max_hp;
			}
		}
		current_mana -= CLERIC_ABILITY_COST;
		return true;
	}
	else if (current_mana < CLERIC_ABILITY_COST) { return false; }

}