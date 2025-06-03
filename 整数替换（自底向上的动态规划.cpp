#include <iostream>
#include <math.h>
#include <vector>

int integerReplacement(int n)
{
    std::vector<int> dp(n+1,0);
    for (int i = 2; i < n+1; i++)
    {
        if(i%2 == 0)
        {
            dp[i] = dp[i/2]+1;
        }
        else
        {
            dp[i] = std::min(dp[i-1]+1,dp[(i+1)/2]+2);
        }  
    }
    return dp[n];
}

int main()
{
    // int n = 7;
    // int n = 8;
    // int n = 4;
    int n = 100090000;
    std::cout<<integerReplacement(n)<<std::endl;


    return 0;
}