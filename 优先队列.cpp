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
void up(int i);
void init();

// 优先队列
// 将一个元素插入到优先队列中
void insert(int key);
// 返回优先队列中的最大元素（对于最大优先队列）
int getMax();
// 移除并返回优先队列中的最大元素（对于最大优先队列）。
int extractMax();
// 将优先队列中某个元素的键值增加到一个新的值（对于最大优先队列）。
void increase_key(int i,int key);


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
//  插入
    init();
    // show();
    // insert(55);
    // show();
    
//返回最大值
    // std::cout<<getMax();

// 返回最大值并删除
    // show();
    // std::cout<<extractMax();
    // std::cout<<std::endl;
    // show();

// 将优先队列中某个元素的键值增加到一个新的值（对于最大优先队列）。
    show();
    increase_key(8,12);
    show();

    return 0;
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
    
    if(r < size && tree[t] <= tree[r])
        t = r;

    if(t != i)
    {
        exchange(i,t);
        down(t);
    }    

}



void up(int i)
{
    int f = getFather(i);
    if(f != 0 && tree[f]<tree[i])
    {
        exchange(i,f);
        up(f);
    }
}

void init()
{
    for (int i = size/2; i >= 1; i--)
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
    std::cout<<std::endl;  
}

void exchange(int i,int t)
{
    int temp = tree[t];
    tree[t] = tree[i];
    tree[i] = temp;
}



// 优先队列
void insert(int key)
{
    tree[size] = key;
    size++;
    up(size-1);
}


int getMax()
{
    return tree[1];
}

int extractMax()
{
    int res = tree[1];
    tree[1] = tree[size-1];
    down(1);
    size--;
    return res;
}


void increase_key(int i,int key)
{
    if(key > tree[i])
    {
        tree[i] = key;
        up(i);
    }
    else
    {
            std::cerr << "Error: new key is smaller than current key" <<std::endl;
    }
}

