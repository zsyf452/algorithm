#include <iostream>
#include <functional>
#include <thread>
#include <queue>
#include <mutex>
#include <atomic>
#include <condition_variable>


std::condition_variable cv;
std::mutex mtx;
int res = 0;
int state = 0;
bool isEnd = false;


//打印零
void zero();
// 打印偶数
void even();
// 打印奇数
void odd();

void run();



int main()
{
    res = 5;
    run();
    return 0;
}




//打印零
void zero()
{
    bool isEven = false;
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return state == 0 || isEnd; });

        if(isEnd) return;

        std::cout<<0<<"\n";
        if(res == 0)
        {
            isEnd = true;
            cv.notify_all();
            return;
        }
        if(isEven)
        {
            state = 2;
            isEven = false;
        }
        else
        {
            state = 1;
            isEven = true;
        }

        cv.notify_all();
    }

}



// 打印偶数
void even()
{
    for(int i = 1;true;i++)
    {
        i++;
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return state == 2 || isEnd; });
        if(isEnd) return;
        std::cout<<i<<"\n";
        if(res == i)
        {
            isEnd = true;
            cv.notify_all();
            return;
        }

        state = 0;
        cv.notify_all();
}


}



// 打印奇数
void odd()
{
    for(int i = 0;true;i++)
    {
        i++;
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return state == 1 || isEnd; });
        if(isEnd) return;
        
        std::cout<<i<<"\n";
        
        
        if(res == i)
        {
            isEnd = true;
            cv.notify_all();
            return;
        }

        state = 0;
        cv.notify_all();
    }


}



void run()
{
    std::thread t1(zero);
    std::thread t2(even);
    std::thread t3(odd);

    t1.join();
    t2.join();
    t3.join();
}