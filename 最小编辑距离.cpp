#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int func(std::string word1, std::string word2);

int main()
{
    std::cout<<"res: "<<func("horse","ros")<<std::endl;
    // std::cout<<"res: "<<func("intention","execution")<<std::endl;
    // std::cout<<"res: "<<func("a","b")<<std::endl;
    // std::cout<<"res: "<<func("a","a")<<std::endl;
    return 0;
}



int func(std::string word1, std::string word2)
{
    int n = word1.size()+1,m = word2.size()+1;
    std::vector<std::vector<int>> dp(n,std::vector<int>(m));
    for(int i = 0;i<n;i++) dp[i][0] = i;
    for(int i = 0;i<m;i++) dp[0][i] = i;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(word1[i-1] == word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = std::min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
        
    }
    
    

    return dp[n-1][m-1];
}