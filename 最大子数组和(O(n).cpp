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
    int res = 0;
    int thisNum = 0;
    for(int &num : nums)
    {
        thisNum += num;
        if(thisNum > res)
        {
            res = thisNum;
        }
        else if(thisNum < 0)
        {
            thisNum  = 0;
        }
    }
    

    return res;
}