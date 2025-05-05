#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define inf 9999

int minPathSum(std::vector<std::vector<int>>& grid);


int main()
{
    std::vector<std::vector<int>> grid{
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    // 7


    // std::vector<std::vector<int>> grid{
    //     {1,2,3},
    //     {4,5,6}
    // };
    // 12

    std::cout<<minPathSum(grid)<<std::endl;
    return 0;
}

int minPathSum(std::vector<std::vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    std::vector<std::vector<int>> dp(n,std::vector<int>(m,inf));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // dp[i][j+1]
            // dp[i+1][j]
            if(j+1 != m)
                dp[i][j+1] = std::min(dp[i][j+1],dp[i][j]+grid[i][j+1]);
            if(i+1 != n) 
                dp[i+1][j] = std::min(dp[i+1][j],dp[i][j]+grid[i+1][j]);


        }
        
    }
    


    return dp[n-1][m-1];
}