#include <iostream>

using namespace std;


//Fibonacci series using recursion
// 1 1 2 3 5 8 13 ..


/**
 * @brief fibonacci Outputs the next number in the fibonacci sequence
 * @param n Input number
 * @return Output num in the sequence
 */
int fibonacci(int n) {
    if (n == 1 || n == 2){
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


int main()
{
    cout << "Hello World!" << endl;


    int n = 10;

    for(int i =1; i <= n; i++) {
        std::cout<<" "<<fibonacci(i)<<" ";
    }

    std::cout<<"\n";

    return 0;
}
