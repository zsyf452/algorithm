#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>


int n = 0;
std::condition_variable cv;
std::mutex mtx;
int state = 0;


void foo();
void bar();
void run();

int main()
{
    n = 10000;
    run();

    while(true);
    return 0;
}


void foo() 
{
    for (int i = 0; i < n; i++)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[](){
            return state == 0;
        });

        std::cout<<"foo";
        state = 1;
        lock.unlock();
        cv.notify_all();
    }
}

void bar() 
{
    for (int i = 0; i < n; i++) 
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[](){
            return state == 1;
        });
        std::cout<<"bar\n";
        state = 0;
        lock.unlock();
        cv.notify_all();
    }
}



void run()
{
    std::thread(foo).detach();
    std::thread(bar).detach();

}

