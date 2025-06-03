#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int longestCommonSubstring(std::string text1, std::string text2);

int main()
{
    // std::string text1 = "abcde", text2 = "bbabcde";
    // std::string text1 = "abc", text2 = "abc";
    // std::string text1 = "def", text2 = "abc";
    std::string text1 = "BDCABA", text2 = "ABCBDAB";

    std::cout<<longestCommonSubstring(text1,text2);
    return 0;
}


int longestCommonSubstring(std::string text1, std::string text2)
{
    int n = text1.size();
    int m = text2.size();
    int res = 0;

    std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,0));

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(text1[i-1] == text2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                res = std::max(res,dp[i][j]);
            }
        }
        
    }
    

    return res;
}