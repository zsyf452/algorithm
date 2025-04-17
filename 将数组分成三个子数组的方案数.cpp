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
    int mid_sum = sum(nums);
    int left_sum = 0;
    int right_sum = 0;
    int tsum = 0;
    size_t size = nums.size();

    int i=0,j=0;
    for (int j = size-1; j >= 0 && j!=i; j--)
    {
        left_sum = 0;    
        
        mid_sum -= nums[j];
        right_sum += nums[j];
        
        tsum = mid_sum;
        for (int i = 0; i < size && i!=j && left_sum <= tsum ; i++)
        {
            tsum -= nums[i];
            left_sum += nums[i];
            if(left_sum <= tsum && right_sum >= tsum)
            {
                res++;
            }   
        }
        
        
        
    }
    


    return res;
}