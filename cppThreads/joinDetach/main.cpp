//Includes
#include <iostream>
#include <thread>
#include <chrono>

//Basic Example of Detech and Join thread methods

void longProcess() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"\nCompleted Long\n";
}

void shortProcess() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"\nCompleted Short\n";
}


int main(){

    std::thread t1(shortProcess);
    std::thread t2(std::move(t1)); // this leaves t1 as an empty thread object

    if(t1.joinable())
            t1.join();
    t2.join();


    std::cout<<"\nCompleted\n";
}
