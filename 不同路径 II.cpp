#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);


int main()
{

    std::vector<std::vector<int>> obstacleGrid{
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };


    std::cout<<uniquePathsWithObstacles(obstacleGrid)<<std::endl;
    return 0;
}



int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
    int n = obstacleGrid.size() ,m = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(n,std::vector<int>(m,0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = 1; 
    }
    
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1; 
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(obstacleGrid[i][j] != 1)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
    }
    


    return dp[n-1][m-1];
}