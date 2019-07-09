#include <iostream>

using namespace std;


//Check if the array is sorted using recrsion


bool isSortedAscending(int ar[],int n) {
    if(n == 1)
        return true;
    else {
        return ar[n-1] < ar[n-2] ? false: isSortedAscending(ar,n-1);
    }
}

bool isSortedDescending(int ar[],int n) {
    if(n == 1)
        return true;
    else {
        return ar[n-1] > ar[n-2] ? false: isSortedDescending(ar,n-1);
    }
}

int main()
{
    cout << "Hello World!" << endl;

    int ar[] = {1,2,3,4,5};
    int ar1[] = {6,5,4,3,2,1};

    std::cout<<"Array is sorted :  "<<isSortedAscending(ar,5)<<std::endl;
    std::cout<<"Array is sorted :  "<<isSortedDescending(ar1,6)<<std::endl;

    return 0;
}
