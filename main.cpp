#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>

std::condition_variable cv;
std::mutex mtx;
int state = 0;

std::function<void()> tasks[] ={
    [](){
        std::unique_lock<std::mutex> lock(mtx); 
        cv.wait(lock,[](){
            return state == 0;
        });
        // lock.lock();
        state++;
        std::cout<<"first"<<std::endl;
        lock.unlock();
        cv.notify_all();
    },
    [](){
        std::unique_lock<std::mutex> lock(mtx); 
        cv.wait(lock,[](){
            return state == 1;
        });
        // lock.lock();
        state++;
        std::cout<<"second"<<std::endl;
        lock.unlock();
        cv.notify_all();
    },
    [](){
        std::unique_lock<std::mutex> lock(mtx); 
        cv.wait(lock,[](){
            return state == 2;
        });
        // lock.lock();
        state++;

        std::cout<<"third"<<std::endl;
        lock.unlock();       

        cv.notify_all();
    }
};

void run(std::function<void()> func);


int main()
{
    
    for(const auto &func : tasks)
    {
        run(func);
    }    


    while(true);
    return 0;
}




void run(std::function<void()> func)
{
    std::thread([func](){
        func();
    }).detach();

}