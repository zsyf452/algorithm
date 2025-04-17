#include <iostream>
#include <vector>

int sum(std::vector<int> &nums);
int func(std::vector<int> &nums);

int main()
{
    // 测试1
    std::vector<int> nums = {1,2,2,2,5,0};
    
    //测试2
    // std::vector<int> nums = {1,1,1};

    int res = func(nums);
    std::cout<<"res: "<<res<<std::endl;

    return 0;
}



int sum(std::vector<int> &nums)
{
    int res = 0;
    size_t size = nums.size();
    for (int i = 0; i < size; i++)
    {
        res += nums[i];
    }
    return res;
}   

int func(std::vector<int> &nums)
{
    int res = 0;
    int mid_sum = 0;
    int left_sum = 0;
    int total_sum = sum(nums);
    int right_sum = 0;
    int tsum = 0;
    size_t size = nums.size();

    int i = 0,j = 0;
    for (j = size-1; j >= 0 ; j--)
    {
        right_sum += nums[j];
        left_sum = 0;
        mid_sum = 0;
        for (i = j-1; i > 0; i--)
        {
            mid_sum += nums[i];
            left_sum = total_sum - right_sum - mid_sum;
            if(left_sum <= mid_sum && right_sum >= mid_sum )
            {
                res++;
            }
            
        }
                
    }
    
    

    return res;
}