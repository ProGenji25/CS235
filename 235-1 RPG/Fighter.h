#pragma once
#include "FighterInterface.h"
using namespace std;

class Fighter : public FighterInterface
{
public:
	Fighter(std::string name, int max_hp, int strength, int speed, int magic);
	~Fighter();

	std::string getName() const;
	int getMaximumHP() const;
	int getCurrentHP() const;
	int getStrength() const;
	int getSpeed() const;
	int getMagic() const;
	void takeDamage(int damage);

protected:
	std::string name;
	std::string type;
	int max_hp;
	int current_hp;
	int strength;
	int speed;
	int magic;
};