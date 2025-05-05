#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int book[1000];
long long func(int n);

int main()
{
    std::cout<<func(4)<<std::endl;
    return 0;
}

long long func(int n)
{
    if(n == 0 || n == 1)
        return 1;
    
    if(book[n] != 0)
        return book[n];
    
    
    book[n] = func(n-1) + func(n-2);
    return book[n];
}

