#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int maxSubArray(std::vector<int>& nums);

int main()
{
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // 6

    // std::vector<int> nums = {5,4,-1,7,8};
    // 23


    // std::vector<int> nums = {1};
    // 1

    std::cout<<maxSubArray(nums)<<std::endl;
    return 0;
}




int maxSubArray(std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<int> dp(n,0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {   
        int t = 0;
        for (int j = i; j >= 0; j--)
        {
            t += nums[j];
            // dp[i] = std::max(dp[i],t);
            if(dp[i] < t)
            {
                dp[i] = t;
                if(res < dp[i])
                {
                    res = dp[i];
                }
            }
        }
        
    }

    

    

    return res;
}