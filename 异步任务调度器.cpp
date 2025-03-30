#include <iostream>
#include <functional>
#include <thread>
#include <queue>
#include <mutex>
#include <atomic>
#include <condition_variable>


// 共享资源
std::queue<std::function<void()>> tasks;
std::mutex mtx;
std::condition_variable cv;
std::atomic<int> running_tasks{0};
const int MAX_CONCURRENCY = 2;  // 最大并发数


void addTaskAsyn(const std::function<void()>& func, const std::function<void()>& callback);

void runTaskAsyn();



// 测试任务列表
std::function<void()> task_list[] = {
    []{ std::this_thread::sleep_for(std::chrono::milliseconds(1000)); std::cout << "task: 1\n"; },
    []{ std::this_thread::sleep_for(std::chrono::milliseconds(500));  std::cout << "task: 2\n"; },
    []{ std::this_thread::sleep_for(std::chrono::milliseconds(800));  std::cout << "task: 3\n"; },
    []{ std::this_thread::sleep_for(std::chrono::milliseconds(200));  std::cout << "task: 4\n"; }
};

int main()
{
    // 添加所有任务
    for (const auto& func : task_list) {
        addTaskAsyn(func, []{
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "add success!!!!\n";
        });
    }

    // 启动执行器（2个并发工作线程）
    runTaskAsyn();

    // 保持程序运行
    std::this_thread::sleep_for(std::chrono::seconds(3));
    // while(true);

    return 0;
}



void addTaskAsyn(const std::function<void()>& func, const std::function<void()>& callback)
{
    std::lock_guard<std::mutex> lock(mtx);
    tasks.push([func,callback](){
        func();
        callback();
    });
    cv.notify_one();
}

void runTaskAsyn()
{
    for (int i = 0; i < MAX_CONCURRENCY; i++)
    {
        std::thread([](){
            while(true)
            {
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(mtx);
                    cv.wait(lock,[](){
                        return !tasks.empty() || running_tasks == 0; 
                    });

                    if(tasks.empty())
                        continue;


                    task = tasks.front();
                    tasks.pop();
                    running_tasks++;
                }
                task();
                running_tasks--;

            }
        }).detach();
    }
              


}

