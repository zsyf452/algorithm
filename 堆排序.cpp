#include <iostream>

const long MAX = 999999;
const long MIN = -999999;

int tree[100];
int size = 1;

inline int getLeft(int i){return i*2;}
inline int getRight(int i){return i*2+1;}
inline int getFather(int i){return i/2;}

void exchange(int i,int t);
void show();
void down(int i);
void sort();
void init();

int main()
{

    int arr[] = {23,43,12,2,1,23,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<len;i++)
    {
        tree[size] = arr[i];
        size++;
    }
    
    // size++;
    init();
    sort();
    // show();
    return 0;
}



void sort()
{
    for (int i = 1; i < size; i++)
    {       
        std::cout<<tree[1]<<' ';
        tree[1] = MIN;
        exchange(1,size);
        down(1);   
        // size--;
    }
    
}

void down(int i)
{
    int l = getLeft(i);
    int r = getRight(i);

    int t = 0;
    if(l<size && tree[i] < tree[l])
        t = l;
    else
        t = i;
    
    if(r < size && tree[t] < tree[r])
        t = r;

    if(t != i)
    {
        exchange(i,t);
        down(t);
    }    

}

void init()
{
    for (int i = size/2+1; i >= 1; i--)
    {
        down(i);
    }
    

}


void show()
{
    for (int i = 1; i < size; i++)
    {
        std::cout<<tree[i]<<' ';
    }
    
}

void exchange(int i,int t)
{
    int temp = tree[t];
    tree[t] = tree[i];
    tree[i] = temp;
}