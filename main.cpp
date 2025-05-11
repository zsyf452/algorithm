#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <stack>


bool predictTheWinner(std::vector<int>& nums);

int main()
{
    // std::vector<int> nums = {1,5,2};
    // std::vector<int> nums = {9};
    // std::vector<int> nums = {1, 2, 3, 4};
    // std::vector<int> nums = {1000, 100, 1, 1000};

    std::vector<int> nums = {1, 5, 233, 7};


    std::cout<<predictTheWinner(nums)<<std::endl;

    return 0;
}





bool predictTheWinner(std::vector<int>& nums)
{
    int n = nums.size();

    int p1_score = 0, p2_score = 0; 
    int turn = 0; 
    



    
    
    

    return p1_score == std::max(p1_score,p2_score) ? true:false;
}
