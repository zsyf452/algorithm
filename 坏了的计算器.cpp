

// 在显示着数字 startValue 的坏计算器上，我们可以执行以下两种操作：

// 双倍（Double）：将显示屏上的数字乘 2；
// 递减（Decrement）：将显示屏上的数字减 1 。
// 给定两个整数 startValue 和 target 。返回显示数字 target 所需的最小操作数。
#include <iostream>

struct note
{
    int date;
    int step;
};

note queue[100000];
int begin=0,end=1;
int book[1000];

void brokenCalc(int startValue, int target);

int main()
{
    brokenCalc(2,3);
    std::cout<<queue[end-1].step;
    return 0;
}

void brokenCalc(int startValue, int target)
{
    queue[0].date = startValue;
    queue[0].step = 0;


    while(begin != end)
    {
        for(int i=1;i<=2;i++)
        {
            int nextDate=0;
            if(i==1)
                nextDate = queue[begin].date-1;
            else
                nextDate = queue[begin].date*2;

            if(nextDate > target || nextDate < 0 || book[nextDate] == 1)
                continue;


            book[nextDate] = 1;
            queue[end].date = nextDate;
            queue[end].step = queue[begin].step+1;
            end++;

            if(nextDate == target)
                return;

        }
        begin++;
    }
    
}