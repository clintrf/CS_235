#include "Pathfinder.h"
using namespace std;
#include <algorithm>
#include <stdio.h>  
#include <stdlib.h>     
#include <time.h>

string Pathfinder::toString() const{
    stringstream ss;
    for (int z = 0; z < Z_SIZE; z++){
        for (int y = 0; y < Y_SIZE; y++){
            for(int x = 0; x < X_SIZE; x++){
                ss << maze_grid[x][y][z];
                if(x !=X_SIZE-1){
                    ss << " ";
                }
            }
            ss << endl;
        }
        if(z != Z_SIZE-1){
            ss << endl;
        }
    }
    return ss.str();
}
void Pathfinder::createRandomMaze(){
    for (int z = 0; z < Z_SIZE; z++){
        for (int y = 0; y < Y_SIZE; y++){
            for (int x = 0; x < X_SIZE; x++){
                
                int randNum = rand()%2;
                maze_grid[x][y][z] = randNum;
            }
        }
    }
    maze_grid[0][0][0] = 1;
    maze_grid[4][4][4] = 1;
}
bool Pathfinder::importMaze(string file_name){
    ifstream file (file_name.c_str());
    for (int z = 0; z < Z_SIZE; z++){
        for (int y = 0; y < Y_SIZE; y++){
            for (int x = 0; x < X_SIZE; x++){
                current_maze_grid[x][y][z] = maze_grid[x][y][z];
            }
        }
    }
    if (file.is_open() ){
        string line;
        for (int z = 0; z < Z_SIZE; z++){
            for (int y = 0; y < Y_SIZE; y++){
                getline(file, line);
                stringstream ss(line);
                if (line.empty()){
                    y--;
                }
                else{
                    for (int x = 0; x < X_SIZE; x++){
                        int value =9;
                        ss >> value;
                        if (value != 1 && value != 0){
                            return (false);
                        }
                        maze_grid[x][y][z] = value;
                    }
                }
            }
            if ((z == Z_SIZE-1 && !file.eof()) ||
                (z != Z_SIZE-1 && file.eof()) ||
                (z == Z_SIZE-1 && maze_grid[X_SIZE-1][Y_SIZE-1][Z_SIZE-1] != 1) ||
                (z == 0 && maze_grid[0][0][0] != 1)
            ){
                for (int z = 0; z < Z_SIZE; z++){
                    for (int y = 0; y < Y_SIZE; y++){
                        for (int x = 0; x < X_SIZE; x++){
                            maze_grid[x][y][z] = current_maze_grid[x][y][z];
                        }
                    }
                }
                return (false);
            }
        }
        return (true);
    }
    else{
        return (false);
    }
}
bool Pathfinder::find_maze_path(int grid[X_SIZE][Y_SIZE][Z_SIZE], int x, int y, int z){
	  cout << "find_maze_path ["<<x<<"]["<<y<<"]["<<z<<"]"<<endl;
	  cout << this->toString();
	  if (x < 0 || y < 0 || z < 0 || x >= X_SIZE || y >= Y_SIZE || z >=Z_SIZE){
	    return (false);      // Cell is out of bounds.
	  }
	  else if (grid[x][y][z] != 1){
	    return false;      // Cell is on barrier or dead end.
	  }
	  else if (x == X_SIZE - 1 && y == Y_SIZE - 1 && z == Z_SIZE - 1) {
	    grid[x][y][z] = 1;         // Cell is on path
	    solution.push_back("("+to_string(x)+", "+to_string(y)+", "+to_string(z)+")");
	    
	    return true;               // and is maze exit.
	  }
	  else { 
	    // Recursive case.
	    // Attempt to find a path from each neighbor.
	    // Tentatively mark cell as on path.
	    grid[x][y][z] = 3;
	    if (find_maze_path(grid, x - 1, y, z)
	        || find_maze_path(grid, x + 1, y, z)
	        || find_maze_path(grid, x, y - 1, z)
	        || find_maze_path(grid, x, y + 1, z)
	        || find_maze_path(grid, x, y, z - 1)
	        || find_maze_path(grid, x, y, z + 1)) {
	      solution.push_back("("+to_string(x)+", "+to_string(y)+", "+to_string(z)+")");
	      
	      return true;
	    }
	    else {
	      grid[x][y][z] = 2;  // Dead end.
	      if (solution.size()>0){
	        //solution.pop_back();
	      }
	      return false;
	    }
	  }
}
vector<string> Pathfinder::solveMaze(){
    solution.clear();
    int copy_maze_grid[X_SIZE][Y_SIZE][Z_SIZE];
    for (int z = 0; z < Z_SIZE; z++){
        for (int y = 0; y < Y_SIZE; y++){
            for (int x = 0; x < X_SIZE; x++){
                copy_maze_grid[x][y][z] = maze_grid[x][y][z];
            }
        }
    }
    
    find_maze_path(copy_maze_grid, 0,0,0);
	for(auto s:solution) {
		cout <<s<<endl;
	}
    reverse(solution.begin(),solution.end());
    return (solution);

}