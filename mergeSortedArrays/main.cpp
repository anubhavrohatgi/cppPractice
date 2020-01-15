#include <bits/stdc++.h>

using namespace std;


int* merge(int Arr1[], int Arr2[], int size1, int size2)
{
    int* res = new int[size1+size2];

    int i=0,k=0,j=0;

    //Complexity is O(n+m)
    while(i < size1 && j < size2){
        if(Arr1[i] < Arr2[j]){
            //hold j const
            cout<<"\nValue of i before = "<<i<<endl;
            res[k++] = Arr1[i++];
            cout<<"\nValue of i after = "<<i<<endl;
        } else {
            //hold i const
            cout<<"\nValue of j before = "<<j<<endl;
            res[k++] = Arr2[j++];
            cout<<"\nValue of j before = "<<j<<endl;
        }
    }

    //lets copy the remaining elements in case less
    while(i < size1){
        res[k++] = Arr1[i++];
    }

    while(j < size2){
        res[k++] = Arr2[j++];
    }

    return res;
}


int main()
{
    int size1 = 4;
    int size2 = 5;
    int arr1[] = {1,2,4,7};
    int arr2[] = {3,5,7,8,9};

    //call the function
    int* res = merge(arr1,arr2,size1,size2);

    cout<<"\nArray After merging : ";
    for(int i =0; i < (size1+size2); ++i){
        cout<<"\n"<<res[i];
    }

    cout<<endl;
    return 0;
}
