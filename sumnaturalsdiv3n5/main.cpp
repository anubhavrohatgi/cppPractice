/*
 *  Sum of naturals divisible by 3 and 5
 *  Write a program that calculates and prints the sum of all the natural numbers divisible by
 *  either 3 or 5, up to a given limit entered by the user.
 */


#include <iostream>

using namespace std;



int sumNaturaldiv3n5(int n)
{

    if(n == 1){
        return 0;
    }

    if((n%3==0) && (n%5==0)){
        std::cout<<"\n Add  :"<<n<<std::endl;
        return n + sumNaturaldiv3n5(n-1);
    } else {
        std::cout<<"\n Skip : "<<n<<std::endl;
        return sumNaturaldiv3n5(n-1);
    }
}


int main()
{
    int n = 100;
    int sum = sumNaturaldiv3n5(n);
    std::cout<<"\nRec sum = "<<sum<<std::endl;

    return 0;
}
