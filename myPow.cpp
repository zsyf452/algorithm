#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n);


int main()
{     
    printf("%f \n",myPow(2,0));
    return 0;
}



double myPow(double x, int n)
{
    // 分三个情况 
    // 1.大于 0
    // 2.小于 0
    // 3.等于 0
    double res = 1;
    if(n > 0)
    {
        for(int i = 0;i < n;i++)
        {
            res *= x;
        }
    }
    else if(n < 0)
    {

        for(int i = 0;i < n*-1;i++)
        {
            res *= x;
        }
        res = 1/res;
    }
    
    return res;
}