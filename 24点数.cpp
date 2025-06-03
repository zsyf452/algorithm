#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

struct note
{
    int data;
    int prev;             
    std::string describe;  
    int used_mask;
};






void solve24_bfs(const std::array<int,4> &nums)
{
    note queue[1000];
    int begin=0,end=1;
   
    int next_step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    // auto max_it = std::max_element(nums.begin(), nums.end());
    // std::vector<bool> book(*max_it,false);

    for (int i = 0; i < 4; ++i)
    {
        queue[end++] = {nums[i], -1, std::to_string(nums[i]), 1 << i};
    }

    while(begin < end)
    {
        for (int i = 0; i < 4; i++)
        {
            if ((queue[begin].used_mask >> i) & 1) continue;
            for(int j=0;j<4;j++)
            {
                int res = 0;
                std::string describe = "";
                switch (j)
                {
                case 0:
                    res = queue[begin].data +  nums[i];
                    describe = std::to_string(queue[begin].data) + "+" + std::to_string(nums[i]) + "=" + std::to_string(res);
                    break;
                case 1:
                    res = queue[begin].data -  nums[i];
                    describe = std::to_string(queue[begin].data) + "-" + std::to_string(nums[i]) + "=" + std::to_string(res);
                    break;
                case 2:
                    res = queue[begin].data * nums[i];
                    describe = std::to_string(queue[begin].data) + "*" + std::to_string(nums[i]) + "=" + std::to_string(res);
                    break;
                case 3:
                
                    if (nums[i] == 0 || queue[begin].data % nums[i] != 0) continue;                
                    res = queue[begin].data / nums[i];
                    describe = std::to_string(queue[begin].data) + "/" + std::to_string(nums[i]) + "=" + std::to_string(res);
                    break;

                default:
                    break;
                }

            
                // if(book[])

                queue[end++] = {res, begin, describe, queue[begin].used_mask | (1 << i)};

                if(queue[end-1].data == 24 && (queue[end-1].used_mask == 0b1111))
                {
                    std::vector<std::string> temp;
                    int index = end-1;
                    while(index != -1)
                    {
                        
                        temp.push_back(queue[index].describe);
                        index = queue[index].prev;
                    }
                    temp.pop_back();

                    int n = temp.size();
                    for(int w = n-1;w >= 0 ;w--)
                    {
                        std::cout<<temp[w]<<std::endl;   
                    }
                    
                    std::cout<<"--------------------------------------------\n";   
                    
                }

            }
            
            // process.pop();
        }
        begin++;
    }
}


int main()
{
    std::array<int ,4> nums = {11,3,1,8};

    solve24_bfs(nums);

    // std::cout<<queue[end-1].step;
    return 0;
}