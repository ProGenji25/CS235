#pragma once

#include "ArenaInterface.h"
#include "Fighter.h"
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"
using namespace std;

class Arena : public ArenaInterface
{
public:
	Arena();
	~Arena();

	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize() const;

private:
	vector <Fighter*> my_arena;
	int findFighter(string target);

};