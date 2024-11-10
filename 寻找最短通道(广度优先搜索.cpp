#include <iostream>
#include <stdio.h>

struct note
{
    int x;
    int y;
    int step;
    note *last;
};



note *queue = new note[1000000];
int begin=0,end=1;

int book[100][100];

// const int Y_MAX = 5;
// const int X_MAX = 4;

// int map[Y_MAX][X_MAX]={
//     {0,0,1,0},
//     {0,0,0,0},
//     {0,0,1,0},
//     {0,1,2,0},
//     {0,0,0,1}
// };

const int X_MAX = 15;
const int Y_MAX = 7;

int map[Y_MAX][X_MAX] = {
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0}
};

void BreadthFirstSearch(int x,int y);
void showMap();

int main()
{
    showMap();
    BreadthFirstSearch(0,0);
    std::cout<<"总共用\033[31m"<<queue[end-1].step<<"\033[0m步"<<std::endl;
    

    note *t = queue[end-1].last;
    while(t != NULL)
    {
        std::cout<<"("<<t->x<<","<<t->y<<")"<<' ';
        map[t->y][t->x] = 9; 
        t = t->last;
    }
    std::cout<<std::endl;
    showMap();

    return 0;
}


void BreadthFirstSearch(int x,int y)
{
    int next_step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    queue[0].x = x;
    queue[0].y = y;
    queue[0].step = 0;
    queue[0].last = NULL;
    book[y][x] = 1;

    while(begin != end)
    {
        for(int i=0;i<4;i++)
        {
            int tx = queue[begin].x + next_step[i][0];
            int ty = queue[begin].y + next_step[i][1];

            if( tx > X_MAX || tx < 0 ||
            ty > Y_MAX || ty <0 ||
            book[ty][tx] == 1 ||
            map[ty][tx] == 1)
                continue;

            queue[end].x = tx;
            queue[end].y = ty;
            queue[end].step = queue[begin].step + 1;
            queue[end].last = &queue[begin];
            end++;

            if(map[ty][tx] == 2)
                return;
        }
        begin++;
    }
}

void showMap()
{
    for(int i= 0;i<Y_MAX;i++)
    {
        for(int j = 0;j<X_MAX;j++)
        {
            if(map[i][j] == 9) 
            {
                std::cout<<"\033[31m"<<map[i][j]<<"\033[0m ";
                continue;
            }
            else if(map[i][j] == 2)
            {
                std::cout<<"\033[32m"<<map[i][j]<<"\033[0m ";
                continue;
            }
            else if(map[i][j] == 0)
            {
                std::cout<<"  ";
                continue;
            }
            std::cout<<map[i][j]<<' ';
        }
            
        std::cout<<std::endl;
    }
        
        
}