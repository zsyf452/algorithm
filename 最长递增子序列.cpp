#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


int func(std::vector<int> &nums);

int main()
{
    // std::vector<int> nums = {1,2,3,4,5,6,7,8,9};
    // std::vector<int> nums = {0,1,0,3,2,3};
    std::vector<int> nums = {10,9,2,5,3,7,101,18};

    std::cout<<"res: "<<func(nums)<<std::endl;
    return 0;
}



int func(std::vector<int> &nums)
{
    int n = nums.size();

    std::vector<int>dp(n,0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0;j<i;j++)
        {
            if( nums[j] < nums[i])
            {
                dp[i] = std::max(dp[i],dp[j]+1);
            }
       }
       res = std::max(res,dp[i]);
    }
    
    return res;
}