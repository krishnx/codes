/* rat in maze.
 * Uses recursion with back tracking.
 */

#include<iostream>
#include<cstdlib>

using namespace std;

void solveMaze(int maze[4][4], int, int);
bool solveMazeUtil(int maze[4][4], int, int, int sol[4][4]);
bool isSafe(int maze[4][4], int, int);
void printSolution(int sol[4][4]);

int main()
{
  int maze[4][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1}
  };
  solveMaze(maze, 0, 0);

  return 0;
}

void solveMaze(int m[4][4], int row, int col)
{
  int sol[4][4] = {0};
  if(!solveMazeUtil(m, row, col, sol)) {
    return ;
  }
  printSolution(sol);
}

bool solveMazeUtil(int m[4][4], int i, int j, int sol[4][4])
{
  if(i == 3 && j == 3) {
    sol[i][j] = 1;
    return true;
  }
  if(isSafe(m, i,j)) {
    sol[i][j] = 1;
    if(solveMazeUtil(m, i+1, j, sol)) {
      return true;
    }
    if(solveMazeUtil(m, i, j+1, sol)) {
      return true;
    }
    sol[i][j] = 0;
    return false;
  }
  return false;
}

void printSolution(int sol[4][4])
{
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) 
      cout << sol[i][j] << " ";
    cout << endl;
  }
}

bool isSafe(int m[4][4], int i, int j)
{
  if( (i>=0) && (i<4) && (j>=0) && (j<4) && (m[i][j] == 1) ) {
    return true;
  } 
  return false;
}
