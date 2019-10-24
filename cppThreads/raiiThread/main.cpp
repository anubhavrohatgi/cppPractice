//Includes
#include <iostream>
#include <thread>


class threadRAII {
private:
    std::thread& th;
public:
    explicit threadRAII(std::thread& t ) : th(t) {

    }

    ~threadRAII() {
        if(th.joinable()) {
            th.join();
            std::cout<<"\n[THREAD_RAII] Destroyed Object & Automatic JOIN"<<std::endl;
        }
        std::cout<<"\n[THREAD_RAII] Destruction accomplished"<<std::endl;
    }

    //delete the copy constructor as thread cannot be copied or assigned
    //only can it be moved
    threadRAII(const threadRAII &)= delete;

    //delete the copy assignment operator
    threadRAII& operator=(const threadRAII &)= delete ;
};


class work1 {
public:
    work1(int x_) : x(x_) {
        ++count;
        std::cout<<"\n[WORKER1] Ctor : "<<count<<std::endl;
    }

    ~work1() {
        std::cout<<"\n[WORKER1] Dtor : "<<count<<std::endl;
    }

    void operator() () {
        for(int i =0; i < x; ++i) {
            std::cout<<"[WORKER1] Printing this :: "<<i<<std::endl;
        }
    }

private:
    int x;
    static int count;
};

int work1::count = 0;

//class work2 {
//public:
//    work2(int x_) : x(x_) {

//    }

//    ~work2() {
//        std::cout<<"\n[WORKER2] Destruction accomplished"<<std::endl;
//    }

//    void operator() () {
//        for(int i =0; i < x; ++i) {
//            std::cout<<"[WORKER2] Printing this :: "<<i<<std::endl;
//        }
//    }

//private:
//    int x;
//};

int main()
{
    int local_main=5;
//    work1 my_func(local_main);
    std::thread t((work1(local_main)));
    t.join();
//    threadRAII g(t);
    std::cout<<"\n[MAIN] From main thread..."<<std::endl;
    return 0;
}
