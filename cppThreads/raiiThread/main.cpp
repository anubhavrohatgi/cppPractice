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
            std::cout<<"\n[THREAD_RAII] Automatic JOIN"<<std::endl;
            th.join();
        }
    }

    //delete the copy constructor as thread cannot be copied or assigned
    //only can it be moved
    threadRAII(const threadRAII &)= delete;

    //delete the copy assignment operator
    threadRAII& operator=(const threadRAII &)= delete ;
};


class work {
public:
    work(int x_) : x(x_) {

    }
    void operator() () {
        for(int i =0; i < x; ++i) {
            std::cout<<"[WORKER] Printing this :: "<<i<<std::endl;
        }
    }

private:
    int x;
};


int main()
{
    int local_main=5;
    work my_func(local_main);
    std::thread t(my_func);
    threadRAII g(t);
    std::cout<<"\n[MAIN] From main thread..."<<std::endl;
    return 0;
}
