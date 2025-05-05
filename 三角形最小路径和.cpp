#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define inf 9999

int minimumTotal(std::vector<std::vector<int>>& triangle);

int main()
{
    // std::vector<std::vector<int>> triangle{
    //     {2},
    //     {3,4},
    //     {6,5,7},
    //     {4,1,8,3}
    // };
    // 11

    // std::vector<std::vector<int>> triangle{
    //     {-10},
    // };
    // -10

    // std::vector<std::vector<int>> triangle{
    //     {1},
    //     {2,3},
    //     {4,5,6},
    //     {7,8,9,10}
    // };
    // 14

    std::vector<std::vector<int>> triangle{
        {5},
        {9,6},
        {4,6,8},
        {0,7,1,5}
    };
    // 18


    std::cout<<minimumTotal(triangle)<<std::endl;  

    return 0;
}



int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    if(triangle.size() == 1) return triangle[0][0];

    int n = triangle.size();
    std::vector<std::vector<int>> dp(n,std::vector<int>(n,inf));
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < n; i++)
    {
        // res = inf;
        int m = triangle[i].size();
        for (int j = 0; j < m; j++)
        {
            if(i+1<n)
            {
                dp[i+1][j] = std::min(dp[i+1][j],dp[i][j]+triangle[i+1][j]);
                if(j+1 < m)
                {
                    dp[i+1][j+1] = std::min(dp[i+1][j+1],dp[i][j]+triangle[i+1][j+1]);
                }
            }            
        }
        
    }
    
    int res = inf;
    for ( int i = 0; i < n; i++)
    {
        res = std::min(res ,dp[n-1][i]);
    }
    

    return res;
}