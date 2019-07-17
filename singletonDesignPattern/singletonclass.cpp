#include "singletonclass.h"

singletonClass* singletonClass::mInstance = nullptr;

singletonClass::singletonClass()
{
    std::cout<<"\n["<<mName<<"] Instantiating Singleton\n";
}


singletonClass* singletonClass::getInstance()
{
    if(mInstance == nullptr){
        std::cout<<"\n[SINGLETON] This should be displayed only once\n";
        mInstance = new singletonClass();
    }

    return mInstance;
}


int singletonClass::addNum(int a, int b)
{
    return  a+b;
}

