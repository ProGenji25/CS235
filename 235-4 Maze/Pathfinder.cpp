#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				maze[i][j][k] = 1;
			}
		}
	}
}

Pathfinder::~Pathfinder() {}

string Pathfinder::toString() const
{
	stringstream ss;
	string s;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (k == 4)
				{
					ss << maze[i][j][k];
				}
				else if (k != 4)
				{
					ss << maze[i][j][k] << " ";
				}
			}
			ss << endl;
		}
		if (i != 4)
		{
			ss << endl;
		}
	}
	s = ss.str();
	return s;
}

void Pathfinder::createRandomMaze()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				maze[i][j][k] = rand() % 2;
			}
		}
	}
	maze[0][0][0] = 1;
	maze[4][4][4] = 1;
}

bool Pathfinder::importMaze(string file_name)
{
	ifstream ifs;
	ifstream ifs2;
	int cell_count = 0;
	int check = 0;
	int count = 0;
	int input = 0;

	ifs2.open(file_name.c_str());
	if (ifs2.is_open())
	{
		while (ifs2 >> input)
		{
			count++;
		}
		if (count != 125)
		{
			return false;
		}
	}
	
	ifs.open(file_name.c_str());
	if (ifs.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (ifs.fail())
					{
						ifs.clear();
						ifs.ignore();
						return false;
					}
					else
					{
						ifs >> maze[i][j][k];
					}

				}
			}
		}
		ifs >> check;
		if (!ifs.fail())
		{
			ifs.clear();
			ifs.ignore();
			return false;
		}
	}
	ifs.close();

	if (maze[0][0][0] == 0 || maze[4][4][4] == 0)
	{
		return false;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (maze[i][j][k] == 0 || maze[i][j][k] == 1)
				{
					cell_count++;
				}
				else if (!isdigit(maze[i][j][k]))
				{
					return false;
				}
				else
				{
					return false;
				}
			}
		}
	}
	if (cell_count != 125)
	{
		return false;
	}
	return true;
}

vector<string> Pathfinder::solveMaze()
{
	P.clear();
	findPath(maze, 0, 0, 0);
	for (int z = 0; z < 5; z++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (maze[x][y][z] == 2 || maze[x][y][z] == 3)
				{
					maze[x][y][z] = 1;
				}
			}
		}
	}
	return P;
}

bool Pathfinder::findPath(int maze[5][5][5], int x, int y, int z)
{
	stringstream ss;
	string position;
	ss << z << ", " << y << ", " << x;
	position = ss.str();
	position = "(" + position + ")";
	P.push_back(position);
	if (x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4 || maze[x][y][z] == 0 || maze[x][y][z] == 3 || maze[x][y][z] == 2)
	{
		P.pop_back();
		return false;
	}
	else if (x == 4 && y == 4 && z == 4)
	{
		return true;
	}
	else if (maze[x][y][z] == 1)
	{
		maze[x][y][z] = 2;
		if (findPath(maze, x - 1, y, z) || findPath(maze, x + 1, y, z) || findPath(maze, x, y - 1, z) || findPath(maze, x, y + 1, z) || findPath(maze, x, y, z - 1) || findPath(maze, x, y, z + 1))
		{
			maze[x][y][z] = 1;
			return true;
		}
		else
		{
			maze[x][y][z] = 3;
			P.pop_back();
			return false;
		}
	}
}
