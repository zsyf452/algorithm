
//接雨水：分层法
/*
这种解法的思路是把多层分为一层
，然后一层一层的去算
优点:简单，稳定
缺点:效率太低，时间复杂度是O(n*h)，所需时间太高
*/


#include <iostream>

int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
// int height[] = {4,2,0,3,2,5};
int len=sizeof(height)/sizeof(int);


int func()
{
    int total=0;
    bool sigen=false;
    int left=0;
    while(sigen == false)
    {
        sigen=true;
        for(int i=0;i<len;i++)
        {
            if(height[i] != 0)
            {
                if(i - left > 1 )
                {
                     total += i - left - 1;
                     left=0;       
                        
                }
                sigen = false;
                left = i;
                height[i]--;
                
            }          
        }
        
     }
    
    return total;
}



int main()
{
    std::cout<<"value:"<<func();
    return 0;
}