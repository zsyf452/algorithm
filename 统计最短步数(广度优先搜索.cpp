#include <iostream>

struct note
{
    int x;
    int y;
    int step;
};

const int Y_MAX = 5;
const int X_MAX = 4;

note queue[1000];
int begin=0,end=1;

int P_overX=4;
int P_overY=3;
int book[100][100];

int map[Y_MAX][X_MAX]={
    {0,0,1,0},
    {0,0,0,0},
    {0,0,1,0},
    {0,1,0,0},
    {0,0,0,1}
};


void BreadthFirstSearch(int x,int y)
{
    
    

    int next_step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    queue[0].x = x;
    queue[0].y = y;
    queue[0].step = 0;
    book[y][x] = 1;

    while(begin < end)
    {
        for(int i=0;i<4;i++)
        {
            int ty = queue[begin].x + next_step[i][0];
            int tx = queue[begin].y + next_step[i][1];

            if( tx > X_MAX || tx < 0 ||
                ty > Y_MAX || ty <0 ||
                book[ty][tx] == 1 ||
                map[ty][tx] == 1)
                    continue;
            
            book[ty][tx] = 1;
            queue[end].x = tx;
            queue[end].y = ty;
            queue[end].step = queue[begin].step + 1;
            end++;

            if(tx == P_overX && ty == P_overY)
                return;

        }
        begin++;
    }
}


int main()
{
    BreadthFirstSearch(0,0);
    std::cout<<queue[end-1].step;
    return 0;
}