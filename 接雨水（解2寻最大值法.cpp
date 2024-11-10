
//接雨水：寻最大值法

// 这种解法的思路是
// 排序后以最大值为基
// 计算最大值到a值的距离相乘最后再减去途中的障碍物（即a*s-obstacle）
// 之前被选为障碍物的索引的值不算做距离


#include <iostream>
#include <cmath>

struct node
{
    int date;
    int index;
};

int book[1000];
int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
// int height[] = {4,2,0,3,2,5};
int len = sizeof(height)/sizeof(int);
node *h = new node[len];

int trap();
void fast_sort(int left,int right);

int main()
{
    for(int i = 0;i<len;i++)
    {
       h[i].date = height[i];
       h[i].index = i;
    }

    fast_sort(0,len-1);
    // for(int i = 0;i<len;i++)
    // {
    //     std::cout<<"i: "<<h[i].index<<' '<<"d: "<<h[i].date<<"\n";
    // }
    std::cout<<"value:"<<trap()<<"\n";
    delete h;
    return 0;
}

void fast_sort(int left,int right)
{
    if(left > right)
        return;

    node temp = h[left];
    int i = left,j = right;

    while (i < j)
    {
        while(temp.date >= h[j].date && i<j)
            j--;
        while(temp.date <= h[i].date && i<j)
            i++;

        if(i > j)
            break;

        node t = h[i];
        h[i] = h[j];    
        h[j] = t;
    }
    
    h[left] = h[j];
    h[j] = temp;

    fast_sort(left,j-1);
    fast_sort(j+1,right);
}

int trap()
{
    int sum = 0;
    int date = h[0].date;
    int index = h[0].index;

    for(int i = 1;i<len;i++)
    {
        if(book[h[i].index] == 1)
            continue;
        int l = abs(index - h[i].index);
        int distance = l;
        int a = index > h[i].index ? h[i].index:index;
        int obstacle = 0;
        for(int j = 1;j<l;j++)
        {
            if(book[a+j] == 1)
            {
                // distance--;
                distance -= j+1;
                // continue;
                break;
            }
                
            // obstacle += height[a+j];
            // int temp_1 = height[a+j];
            // int temp_2 = height[a];
            if(height[a+j]> height[h[i].index])
                obstacle += height[h[i].index];
            else
                obstacle += height[a+j];
            book[a+j] = 1;
        }
        
        // int temp = h[i].date;
        sum += (distance-1) * h[i].date - obstacle;
        
    }

    return sum;
}