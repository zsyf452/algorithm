#include <iostream>

// int nums[] = {1,1,2,8};
// int target = 35;

int nums[] = {1,32,1,2};
int target = 12;

// int nums[] = {1,2,8};
// int target = 7;




int len = sizeof(nums)/sizeof(int);
int sum = 0;

int stack[1000];
int top = len;

int func();
void init();
void fast_sort(int left,int right);

int main()
{
    fast_sort(0,len-1);

    // for(int i =0;i<len;i++)
        // std::cout<<nums[i]<<' ';
     

    for(int i =0;i<len;i++)
        stack[i] = nums[i];
        
    stack[top] = 0;

    init();

    std::cout<<func()<<std::endl;

    
    return 0;
}



int func()
{
    int step = 0;
    while(top != 0)
    {
        if(sum == target)
            return step;
        else if(stack[top] != 0 && sum - stack[top]<target)
        {
            step++;
            int t = top+1;
            stack[top] /= 2;
            stack[t] = stack[top];
            top = t;
            sum -= stack[top];
        }else{
            sum -= stack[top];
            top--;
        }

    }

    return -1;
}



void init()
{
    for(int i = 0;i<len;i++)
        sum += nums[i];
}


void fast_sort(int left ,int right)
{
    if(left > right)
        return;

    int temp = nums[left];
    int i = left,j = right;

    while(i<j)
    {
        while(temp <= nums[j] && i<j)
            j--;
        while(temp >= nums[i] && i<j)
            i++;

        if(i>=j)
            break;
        
        int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;        

    }

    nums[left] = nums[j];
    nums[j] = temp;

    fast_sort(left,j-1);
    fast_sort(j+1,right);

}