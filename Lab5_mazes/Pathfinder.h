#pragma once
#include "PathfinderInterface.h"
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>  
#include <stdlib.h>     
#include <time.h>

using namespace std;

const int X_SIZE = 5;
const int Y_SIZE = 5;
const int Z_SIZE = 5;
const int OPEN_SPACE = 1;
const int WALL = 0;
const int TEMPORARY = 2;
const int PATH = 3;

class Pathfinder: public PathfinderInterface{
public:
    Pathfinder() {
        srand (time(NULL));
        for (int z = 0; z < Z_SIZE; z++){
            for (int y = 0; y < Y_SIZE; y++){
                for (int x = 0; x < X_SIZE; x++){
                    maze_grid[x][y][z] = 1;
                }
            }
        }
    };
	~Pathfinder() {};
	string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
protected:
   
    bool find_maze_path(int grid[X_SIZE][Y_SIZE][Z_SIZE], int x, int y, int z);
    vector<string> solution;
    int maze_grid[X_SIZE][Y_SIZE][Z_SIZE];
    int current_maze_grid[X_SIZE][Y_SIZE][Z_SIZE];
    
};
