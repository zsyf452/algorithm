#include <iostream>

int f[1000];
int n=11,m=10,sum;

int getF(int v)
{
    if(f[v] == v)
        return v;
    else{
        f[v] = getF(f[v]);
        return f[v];
    }
}

void merge(int v,int u)
{
    int t1,t2;
    t1 = getF(v);
    t2 = getF(u);

    f[t2] = f[t1];

}

int main()
{
    int t[10][2] = {
        {1,2},
        {3,4},
        {5,2},
        {4,6},
        {2,6},
        {7,11},
        {8,7},
        {9,7},
        {9,11},
        {1,6}
    };


    for(int i = 0;i<=n;i++)
        f[i] = i;
    
    for(int i=0;i<m;i++)
    {
        merge(f[t[i][0]],f[t[i][1]]);
    }

    for(int i=0;i<m;i++)
    {
        if(f[i] == i)
            sum++;
    }
    std::cout<<sum;

    return 0;
}