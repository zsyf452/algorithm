#include <iostream>

struct note
{
    int x;
    int y;
    int step;
    note *next;
};

const int Y_MAX = 5;
const int X_MAX = 4;

note *begin = NULL,*end = NULL,*p = NULL;

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

    p = new note;
    p->x = x;
    p->y = y;
    p->step = 0;
    p->next = NULL;
    begin = p;
    end = p;
    book[y][x] = 1;


    do
    {
        for(int i=0;i<4;i++)
        {
            int ty = begin->x + next_step[i][0];
            int tx = begin->y + next_step[i][1];

            if( tx > X_MAX || tx < 0 ||
                ty > Y_MAX || ty <0 ||
                book[ty][tx] == 1 ||
                map[ty][tx] == 1)
                    continue;
            

            book[ty][tx] = 1;
            p = new note;
            p->x = tx;
            p->y = ty;
            p->step = begin->step + 1;
            
            end->next = p;
            end = p;

            if(tx == P_overX && ty == P_overY)
                return;

        }
        begin = begin->next;
    }while(begin != end);
}


int main()
{
    BreadthFirstSearch(0,0);
    std::cout<<end->step;
    return 0;
}