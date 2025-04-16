#include <iostream>
#include <functional>
#include <thread>
#include <condition_variable>
#include <queue>
#include <mutex>
#include <atomic>


#define MAX_PRODUCER 2
#define MAX_CONSUMER 2
#define MAX_BUFFER 5
#define MAX_PARA 10


std::queue<int> datas;
std::condition_variable cv;
std::mutex mtx;
std::atomic<int> producerCount(0);
std::atomic<int> consumerCount(0);
//添加生产者
void addProducer();
//添加消费者
void addConsumer();

//生产者行为
void producerFunction(std::atomic<int> &id);
//消费者行为
void consumerFunction(std::atomic<int> &id);


int main()
{
    addProducer();
    addConsumer();
    // std::cout<<"end"<<std::endl;
    while(true);
    return 0;
}



void addProducer()
{
    for(int i = 0;i<MAX_PRODUCER;i++)
    {
        std::thread([](){
            producerCount++;
            producerFunction(producerCount);
        }).detach();
    }
}


void addConsumer()
{
    for(int i = 0;i<MAX_CONSUMER;i++)
    {
        std::thread([](){
            consumerCount++;
            consumerFunction(consumerCount);
        }).detach();
    }
}


void producerFunction(std::atomic<int> &id)
{
    for (int i = 0; i < MAX_PARA; i++)
    {
        int data = rand()%10;
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[](){
            return datas.size() < MAX_BUFFER;
        });

        datas.push(data);
        std::cout<<"生产者"<<id<<"生产了: "<<data<<"   缓冲区存储数: "<< datas.size() <<std::endl;
        
        cv.notify_all();
    }
    

}


void consumerFunction(std::atomic<int> &id)
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[](){
            return !datas.empty();
        });

        int data = datas.front();
        datas.pop();
        
        std::cout<<"消费者"<<id<<"消费了: "<<data<<"   缓冲区存储数: "<< datas.size() <<std::endl;
        cv.notify_all();
        lock.unlock();    

    }

}



