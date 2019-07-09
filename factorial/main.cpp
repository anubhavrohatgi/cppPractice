#include <iostream>

using namespace std;


//factorial of a num -- recursion


/**
 * @brief factorial of number is calculated
 * @param n input num
 * @return output res
 */
long factorial(int n) {
    if(n > 0){
        return n*factorial(n-1);
    } else {
        return 1;
    }
}


int main()
{
    cout << "Hello World!" << endl;

    int n = 5;
    long res = factorial(n);

    std::cout<<"Factorial of ("<<n<<") is = "<<res<<std::endl;

    return 0;
}
