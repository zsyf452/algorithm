#include <iostream>
#include <string>
#include <vector>
#include <array>

struct Queue
{
    std::string data;
    int step;
};

int func(const std::string &beginText,const std::string &endText,const std::vector<std::string> &arr);



int main()
{
    //测试1
    std::vector<std::string> arr = {"hot","dot","dog","lot","log","cog"};
    std::string beginText = "hit";
    std::string endText = "cog";


    //测试2
    // std::vector<std::string> arr = {"hot","dot","dog","lot","log"};
    // std::string beginText = "hit";
    // std::string endText = "cog";


    // std::cout<<"Res: "<<11111111111<<std::endl;
    int res = func(beginText,endText,arr);
    std::cout<<"Res: "<<res<<std::endl;
    return 0;
}




int func(const std::string &beginText,const std::string &endText,const std::vector<std::string> &arr)
{
    int begin = 0;
    int end = 1;

    Queue queue[1000];
    
    std::array<int,1000> book = {0};
    
    queue[begin].data = beginText;
    queue[begin].step = 1;
    


    while(begin != end)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if(book[i] != 0)
            {
                continue;
            }

            int count = 0;

            for (int j = 0; j < queue[begin].data.size() && count <= 2; j++)
            {
                if(queue[begin].data[j] != arr[i][j])
                {
                    count++;
                }
            }
            
            if(count == 1)
            {
                queue[end].data = arr[i];
                queue[end].step = queue[begin].step + 1;
                end++;
                if(queue[end-1].data == endText)
                {
                    // std::cout<<"res :"<<queue[end-1].step<<std::endl;
                    return queue[end-1].step;
                }
            }

        }
        begin++;
        book[begin] = 1;
        
    }
    return 0;
}