#pragma once
#include "PathfinderInterface.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
 


class Pathfinder : public PathfinderInterface
{
public:
	Pathfinder();
	~Pathfinder();

	string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
	bool findPath(int maze[5][5][5], int x, int y, int z);

protected:
	string file_name;
	vector<string> P;
	int maze[5][5][5];
};
