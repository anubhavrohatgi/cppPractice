#include <bits/stdc++.h>

using namespace std;


int* removeEven(int *& Arr, int& size){

    int n =0;

    for(int i =0; i< size; ++i){
        if(Arr[i] %2 != 0){
            if(i != n){
                Arr[n] = Arr[i];
            } else {
                cout<<"\nI==N -> "<<i<<" = "<<n<< " \n";
            }
            ++n;
        }
    } //Complexity is O(n)

    int *temp = new int[n];
    for(int i =0; i < n; ++i){
        temp[i] = Arr[i];
    } //Complexity is O(n)

    delete[] Arr;
    Arr = temp;
    size = n;
    return Arr;
}


int main()
{
    int* arr;
    int size = 9;

    //intialize dynamic array with size
    arr = new int[size];

    //assign values
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    arr[6] = 9;
    arr[7] = 10;
    arr[8] = 11;

    //call the function
    int* res = removeEven(arr,size);

    cout<<"\nArray After removing even integers : ";
    for(int i =0; i < size; ++i){
        cout<<"\n"<<res[i];
    }

    cout<<endl;
    return 0;
}
