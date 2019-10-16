#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

static std::mutex m;



//thread using function pointer
void thread_worker()
{
    for(int i = 0; i < 5; i++) {
        std::lock_guard<std::mutex> n(m);
        std::cout<<"thread function Executing "<<std::this_thread::get_id()<<std::endl;
    }
}


//thread using function object
class DisplayThread
{
public:
    void operator()(){
        for(int i = 0; i < 5; i++) {
            std::lock_guard<std::mutex> n(m);
            std::cout<<"thread function object Executing  "<<std::this_thread::get_id()<<std::endl;
        }
    }
};



//example worker thread
class WorkerThread
{
public:
    void operator()() {
        std::lock_guard<std::mutex> n(m);
        std::cout<<"\nWorker Thread "<<std::this_thread::get_id()<<" is Executing"<<std::endl;
    }
};



void threadCallbackwArgs(int x, std::string str) {
    std::cout<<"Passed Number = "<<x<<std::endl;
    std::cout<<"Passed String = "<<str<<std::endl;
}



int main()
{
    size_t c = std::thread::hardware_concurrency();

    std::cout<<"\n No of concurrent threads = "<<c<<std::endl;


    std::thread threadObj1(thread_worker);
    std::thread threadObj2((DisplayThread()));


    //thread using lambda function
    std::thread threadObj3([]{
        for(int i = 0; i < 2; i++) {
            std::lock_guard<std::mutex> n(m);
            std::cout<<"Display Lambda Thread Executing"<<std::endl;
        }
    });

    std::thread threadObj4(threadCallbackwArgs,10,"anubhav");

    for(int i = 0; i < 6; ++i){
        std::lock_guard<std::mutex> n(m);
        std::cout<<"main function Executing"<<std::endl;
    }
    std::cout<<"Waiting For Thread to complete"<<std::endl;

    threadObj1.join();
    threadObj2.join();
    threadObj3.join();
    threadObj4.join();


    std::cout<<"\nEnded1"<<std::endl;


    std::vector<std::thread> threads;

    for(int k = 0; k < 10; ++k){
        threads.emplace_back(std::thread(WorkerThread()));
    }

    std::cout<<"\nwait for all the worker thread to finish"<<std::endl;

    std::for_each(threads.begin(),threads.end(), std::mem_fn(&std::thread::join));
    std::cout<<"Exiting from Main Thread"<<std::endl;

    threads.clear();


    return 0;
}
