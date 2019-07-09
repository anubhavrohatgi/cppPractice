#include <iostream>

using namespace std;


//Tower of hanoi problem recursion


/**
 * @brief towHanoi Move discs from A to C, move 1 disc at a time.
 *      Total moves = 2^n - 1
 * @param n no of discs
 * @param src Source Tower
 * @param aux Auxiliary Tower
 * @param dst Destination Tower
 */
void towHanoi(int n, char src, char aux, char dst) {

    if(n >= 1) {
        towHanoi(n-1,src,dst,aux);
        std::cout<<" Moved from "<<src<<" to "<<dst<<std::endl;
        towHanoi(n-1,aux,src,dst);
    }
}


int main()
{
    cout << "Hello World!" << endl;

    towHanoi(32,'A','B','C');
    return 0;
}
