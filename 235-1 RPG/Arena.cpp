#include "Arena.h"
#include "Fighter.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"
#include <sstream>

Arena::Arena()
{
	vector <Fighter*> my_arena;
	this->my_arena = my_arena;
}

Arena::~Arena()
{
}

bool Arena::addFighter(string info)
{
	stringstream ss;
	ss << info;
	string name = "";
	string type = "";
	int max_hp = 0;
	int strength = 0;
	int speed = 0;
	int magic = 0;
	int check = 0;

	ss >> name;
	if (ss.fail())
	{
		ss.clear();
		ss.ignore();
		return false;
	}

	if (findFighter(name) != 9999) {
		return false;
	}
	
	ss >> type;
	if (ss.fail())
	{
		ss.clear();
		ss.ignore();
		return false;
	}

	ss >> max_hp;
	if (ss.fail())
	{
		ss.clear();
		ss.ignore();
		return false;
	}

	ss >> strength;
	if (ss.fail())
	{
		ss.clear();
		ss.ignore();
		return false;
	}

	ss >> speed;
	if (ss.fail())
	{
		ss.clear();
		ss.ignore();
		return false;
	}

	ss >> magic;
	if (ss.fail())
	{
		ss.clear();
		ss.ignore();
		return false;
	}

	ss >> check;
	if (!ss.fail())
	{
		ss.clear();
		ss.ignore();
		return false;
	}


	if (type == "R")
	{
		Fighter* robot = new Robot(name, max_hp, strength, speed, magic);
		my_arena.push_back(robot);
		return true;
	}
	else if (type == "A")
	{
		Fighter* archer = new Archer(name, max_hp, strength, speed, magic);
		my_arena.push_back(archer);
		return true;
	}
	else if (type == "C")
	{
		Fighter* cleric = new Cleric(name, max_hp, strength, speed, magic);
		my_arena.push_back(cleric);
		return true;
	}
	else { return false; }
}

bool Arena::removeFighter(std::string name)
{
	if ((findFighter(name)) != 9999) {
		my_arena.erase(my_arena.begin() + findFighter(name));
		return true;
	}
	else {
		return false;
	}
}

FighterInterface* Arena::getFighter(std::string name)
{
	if ((findFighter(name)) != 9999) {
		cout << findFighter(name) << endl;
		return my_arena.at(findFighter(name));
	}
	else {
		return NULL;
	}
}

int Arena::getSize() const
{
	return my_arena.size();
}

int Arena::findFighter(string target)
{
	for (int i = 0; i < my_arena.size(); ++i) {
		if (my_arena.at(i)->getName() == target) {
			return(i);
		}
	}
	return 9999;
}
