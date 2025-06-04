#include <iostream>
#include <vector>
#include <array>
#include <string>

struct Quenue
{
    int data;
    int last;
    int mark;
    std::string describe; 
};


void func24(const std::array<int ,4> nums)
{
    int count = 0;
    Quenue quenue[100000];
    int begin = 0,end = 4;

    for (int i = 0; i < 4; i++)
    {
        quenue[i] = {nums[i],-1,1<<i,std::to_string(nums[i])};
    }
    
    while (begin < end)
    {
        for (int i = 0; i < end; i++)
        {
            const Quenue &curr = quenue[begin];

            if( quenue[i].mark & curr.mark || begin == i)
                continue;

            for (int j = 0; j < 6; j++)
            {
                int res = 0;
                std::string describe = "";
                switch (j)
                {
                case 0:
                    res = curr.data + quenue[i].data;
                    describe = "(" + curr.describe + "+" + quenue[i].describe + ")";
                    break;
                case 1:
                    res = curr.data - quenue[i].data;
                    describe = "(" + curr.describe + "-" + quenue[i].describe + ")";
                    break;
                case 2:
                    res = curr.data * quenue[i].data;
                    describe = "(" + curr.describe + "*" + quenue[i].describe + ")";
                    
                    break;
                case 3:
                    if(quenue[i].data == 0 || curr.data % quenue[i].data != 0)
                        continue;
                    
                    res = curr.data / quenue[i].data;
                    describe = "(" + curr.describe + "/" + quenue[i].describe  + ")";
                    
                    break;
                
                case 4:
                    if(curr.data == 0 ||  quenue[i].data % curr.data != 0)
                        continue;
                    
                    res = quenue[i].data / curr.data;
                    describe = "(" + quenue[i].describe + "/" + curr.describe + ")";
                    break;

                case 5:
                    res = quenue[i].data - curr.data ;
                    describe = "(" + quenue[i].describe + "-" + curr.describe + ")";
                    break;

                default:
                    break;
                }

                quenue[end] = {res ,begin ,quenue[i].mark|curr.mark ,describe};
                end++;

                if(quenue[end-1].data == 24 && quenue[end-1].mark == 0b1111)
                {
                    
                    std::cout<<++count << ": 找到解: " << describe << std::endl;
                }

            }
            

        }
        
        begin++;
    }
    
}



int main()
{

    std::array<int,4> nums = {1,2,3,7};
    func24(nums);

    return 0;
}