#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define inf 9999

int jump(std::vector<int> nums);

int main()
{
    std::vector<int> nums {2,3,1,1,4};
    // std::vector<int> nums {2,3,0,1,4};
    // std::vector<int> nums {1,2,3,4,5};
    // std::vector<int> nums {3,2,1,0,4};
    
    
    std::cout<<jump(nums);

    return 0;
}




int jump(std::vector<int> nums)
{
    int n = nums.size();
    std::vector<int> dp(n,inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= nums[i] && i+j<n; j++)
        {
            // dp[i+j] = dp[i]+1;
            if(dp[i]+1 < dp[i+j])
            {
                dp[i+j] = dp[i]+1;
            }

        }
        
    }
    

    return dp[n-1];    
}