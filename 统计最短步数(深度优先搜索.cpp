#include <iostream>

const int Y_MAX = 5;
const int X_MAX = 4;

int P_overX=4;
int P_overY=3;
int book[100][100];
int min = 99999;

int map[Y_MAX][X_MAX]={
    {0,0,1,0},
    {0,0,0,0},
    {0,0,1,0},
    {0,1,0,0},
    {0,0,0,1}
};


void DepthFirstSearch(int x,int y,int step)
{
    if(x == P_overX && y == P_overY)
    {
        if(min > step)
            min = step;
        return;
    }
    
    int next_step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    for(int i = 0;i<4;i++)
    {
        int tx = x+next_step[i][0];
        int ty = y+next_step[i][1];

        if( tx > X_MAX || tx < 0 ||
            ty > Y_MAX || ty <0 ||
            book[ty][tx] == 1 ||
            map[ty][tx] == 1)
            continue;
        
        book[ty][tx] = 1;
        DepthFirstSearch(tx,ty,step+1);
        book[ty][tx] = 0;
    }

}


int main()
{
    DepthFirstSearch(0,0,0);
    std::cout<<min;
    return 0;
}