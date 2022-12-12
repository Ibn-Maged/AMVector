// This is a maze. A mouse wants to get from
// corner 0, 0 to N-1, N-1
// It can move only to right or down
// It uses backtracking to find 1st way out
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// Maze size
#define N 4

int short_path[N][N];
vector <string> path_long;

void get_all_solution(int maze[N][N], int x, int y, int sol[N][N] , string path);
//-------------------------------------------------------------------------------------------------------------------------------------
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------
void move(int temp[N][N], int temp1[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            temp[i][j]=temp1[i][j];
            
    }


}
//-------------------------------------------------------------------------------------------------------------------------------------
/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}
//-------------------------------------------------------------------------------------------------------------------------------------
/* This function solves the Maze problem using Backtracking.  It mainly
   uses get_all_solution() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s. Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.*/
bool solveMaze(int maze[N][N] , string path)
{
    int sol[N][N] = {{0}};
    get_all_solution(maze, 0, 0, sol , path);

    if(path_long.size()==0)
    {
        printf("Solution doesn't exist");
        return false;
    }

    return true;
}
//-------------------------------------------------------------------------------------------------------------------------------------
/* A recursive utility function to solve Maze problem */
void get_all_solution(int maze[N][N], int x, int y, int sol[N][N] , string path)
{
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        printSolution(sol);
        cout<<"----------------------------------------------------------------"<<endl;
        path_long.push_back(path);
        if(path_long.size()<2)
        move(short_path , sol);
        else {
            if(path_long[path_long.size()-1].length()< path_long[path_long.size()-2].length()){
                move(short_path , sol);
            }
        }
        sol[x][y]=0;
        return;
    }
    
    //down

    if(maze[0][0]==0 or maze[N-1][N-1]==0)
    return;

    if(isSafe(maze, x+1 ,y) and sol[x+1][y]!=1){
        sol[x][y]=1;
        get_all_solution(maze,x+1,y,sol,path+'D');
        sol[x][y]=0;
    }

    //left
    if(isSafe(maze, x ,y-1) and sol[x][y-1]!=1){
        sol[x][y]=1;
        get_all_solution(maze,x,y-1,sol,path+'L');
        sol[x][y]=0;
    }

    //right
    if(isSafe(maze, x ,y+1) and sol[x][y+1]!=1){
        sol[x][y]=1;
        get_all_solution(maze,x,y+1,sol,path+'R');
        sol[x][y]=0;
    }
    //up
    if(isSafe(maze, x-1 ,y) and sol[x-1][y]!=1){
        sol[x][y]=1;
        get_all_solution(maze,x-1,y,sol,path+'U');
        sol[x][y]=0;
    }

}

//-------------------------------------------------------------------------------------------------------------------------------------
void printShortsolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" ", sol[i][j]);
        printf("\n");
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------
// driver program to test above function
int main()
{
    string p="";
    int maze[N][N]  =  {
        {1, 0, 0 ,1},
        {1, 1, 0 , 1},
        {0, 1, 1 , 1},
        {0, 1, 0 , 1},

       
    };
    
    

    if(solveMaze(maze,p) and path_long.size()>1){
        cout<<"------------------------- Short Path --------------------------"<<endl;
        printShortsolution(short_path);
    }

    return 0;
}
