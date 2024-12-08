#include<iostream>

struct Make
{
    int data;
    int right;
    int left;
    int state;
}make[1000];

struct _Make
{
    int left;
    int center;
    int right;
    int sum;
}_make[1000];
int top = 0;



int nums[] = {3,1,5,8};
// int nums[] = {1,5};
int size = sizeof(nums) / sizeof(nums[0]);

int MaxCoins = -1;


void dfs(int step,int coins);
void showMake();

int main()
{
    
    for (int i = 0; i < size; i++)
    {

        make[i].data = nums[i];
        make[i].state = 0;
        make[i].left = i==0?-1:i-1;
        make[i].right = i==size-1?-1:i+1;
        
    }
    
    dfs(0,0);
    std::cout<<MaxCoins<<std::endl;

    return 0;
}

void dfs(int step,int coins)
{
    if(step == size)
    {
        if(coins > MaxCoins)
            MaxCoins = coins;
        
        // showMake();
        // std::cout<<"sum: "<<coins<<"\n\n\n";


        return;
    }


    int left = 0,right = 0,sum = 0;
    for (int i = 0; i < size; i++)
    {
        if(make[i].state == 1)
            continue;

        make[i].state = 1;
        int k = i;
        while(make[k].state == 1 &&  k!=-1)
        {
            k = make[k].left;
        }
        make[i].left = k;

        left = k == -1? 1: make[k].data;
        k=i;
        
        while(make[k].state == 1 &&  k!=-1)
        {
            k = make[k].right;
        }
        make[i].right = k;
        right = k==-1?1:make[k].data;


        sum = left * make[i].data * right;
        // _make[top].left = left;
        // _make[top].center = make[i].data;
        // _make[top].right = right;
        // _make[top].sum = coins;
        // top++;
        coins += sum;

        dfs(step+1,coins);       
        coins -= sum;
        // top--;

        make[i].state = 0;
        make[i].left = i==0?-1:i-1;
        make[i].right = i==size-1?-1:i+1;
    }
    
}

void showMake()
{
    for(int i = 0;i<top;i++)
    {
        std::cout<<"left: "<<_make[i].left
                <<" center: "<<_make[i].center
                <<" right: "<<_make[i].right
                <<" sum: "<<_make[i].sum<<std::endl;
    }

}