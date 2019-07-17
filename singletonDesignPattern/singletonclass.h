#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

#include <iostream>

class singletonClass
{
public:
//    singletonClass(singletonClass const&) = delete;
//    singletonClass& operator=(singletonClass const&) = delete;

    static singletonClass* getInstance();

    int addNum(int a, int b);

private:
    const std::string mName = "SINGLETON";
    singletonClass();
    static singletonClass* mInstance;
};

#endif // SINGLETONCLASS_H
