#include <iostream>

#include "singletonclass.h"

using namespace std;


void accessSingleton(){
    singletonClass* st = singletonClass::getInstance();
    cout<<"\nAccessing ::: "<<st->addNum(100,100)<<endl;
}

int main()
{
    singletonClass* st = singletonClass::getInstance();

    cout <<"\nprocessed : "<<st->addNum(10,12) <<"\nHello World!" << endl;

    accessSingleton();

    return 0;
}
