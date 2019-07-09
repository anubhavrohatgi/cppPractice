#include <iostream>

using namespace std;


//Greatest Common Divisior
//Use Euclids Theorem

/**
 * @brief GCD finds the greatest common divisor of the two numbers
 * @param a INput num a
 * @param b Input num b
 * @return output gcd
 */
int GCD(int a, int b) {
    if(a == b)
        return a;
    if(a%b == 0){
        return b;
    }
    if(b%a == 0) {
        return a;
    }

    if(a > b){
        return GCD(a%b,b);
    } else {
        return GCD(a,b%a);
    }
}


int main()
{
    cout << "Hello World!" << endl;

    int a = 200;
    int b = 20;

    int div = GCD(a,b);
    printf("GCD of %d,%d is = %d \n",a,b,div);

    return 0;
}
