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
            std::cout<<"\n"<<__PRETTY_FUNCTION__<<" Destroyed Object & Automatic JOIN"<<std::endl;
        }
        std::cout<<"\n"<<__PRETTY_FUNCTION__<<" Destruction accomplished"<<std::endl;
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
        std::cout<<"\n"<<__PRETTY_FUNCTION__<<" Ctor : "<<count<<std::endl;
    }

    work1(work1 const& other) : x(other.x)
    {
        std::cout << __PRETTY_FUNCTION__ << ' ' << count << '\n';
    }

    work1& operator=(work1 const& other)
    {
        x = other.x;
        std::cout << __PRETTY_FUNCTION__ << ' ' << count << '\n';
        return *this;
    }

    ~work1() {
        std::cout<<"\n"<<__PRETTY_FUNCTION__<<" Dtor : "<<count<<std::endl;
    }

    void operator() () {
        for(int i =0; i < x; ++i) {
            std::cout<<__PRETTY_FUNCTION__<<" Printing this :: "<<i<<std::endl;
        }
    }

private:
    int x;
    static int count;
};

int work1::count = 0;

class work2 {
public:
    work2(int x_) : x(x_) {

    }

    ~work2() {
        std::cout<<"\n["<<__PRETTY_FUNCTION__<<"] Dtor accomplished"<<std::endl;
    }

    void operator() [[ noreturn ]] () {
        throw "exception reported";
    }

private:
    int x;
};

//int main()
//{
//    work1 w1{5};
//    work2 w2{5};
//    std::thread t1(std::ref(w1));
////    std::thread t2(std::ref(w2));
////    t1.join();
//    threadRAII g1(t1);
////    threadRAII g2(t2);

//    std::cout<<"\n[MAIN] From main thread..."<<std::endl;
//    return 0;
//}


void do_something() {
    throw "exception reported";
}


int main(){
    std::thread t(work1(5));
    threadRAII g(t); // RAII
    do_something(); // exceptions could be called!
    std::cout<<"\n[MAIN] From main thread..."<<std::endl;
    return 0;
}
