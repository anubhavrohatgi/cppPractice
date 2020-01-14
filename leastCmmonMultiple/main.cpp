/*
 *  Least common multiple
 *  Write a program that will, given two or more positive integers, calculate and print the least
 *  common multiple of them all.
 *  lowest common multiple, or smallest common multiple, is the smallest positive integer that
 *  is divisible by all of them.
 *  lcm(a, b) = abs(a*b) / gcd(a, b)
 */


#include <iostream>
#include <math.h>

using namespace std;


uint gcd(uint a, uint b){
    return b ==0 ? a : gcd(b, a%b);
}


uint lcm(uint a, uint b) {
    uint gc = gcd(a,b);
    return gc ? (a* (b/gc)) : 0;
}

int main()
{
    uint a = 6;
    uint b = 9;

    uint lc = lcm(a,b);

    cout << "\n LCM = "<<lc << endl;
    return 0;
}
