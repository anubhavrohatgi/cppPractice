#include <bits/stdc++.h>
using namespace std;


//Given an array of n numbers, our task is to calculate the maximum subar-
//ray sum, i.e., the largest possible sum of a sequence of consecutive values in the
//array . The problem is interesting when there may be negative values in the
//array. eg.
// − 1 | 2 | 4 | −3 | 5 |2 | −5 | 2 |


int maxsumn3(int arr[], int n) {

    //a and b represent
    //left and right bounds of the subarray
    int bestSum = 0;
    for(int a = 0; a < n; a++) {
        for(int b = a; b < n; b++) {
            int sum = 0;
            for(int k = a; k <= b; k++){
                sum += arr[k];
            }
            bestSum = std::max(bestSum,sum);
        }
    }
    return bestSum;
}


int maxsumn2(int arr[], int n){
    int bestSum = 0;

    for(int a =0; a < n; a++){
        int sum = 0;
        for(int b = a; b < n; b++){
            sum += arr[b];
            bestSum = std::max(bestSum,sum);
        }
    }

    return bestSum;
}



int maxsumn1(int arr[], int n){
    int bestSum = 0;
    int sum =0;
    for(int a =0; a < n; a++){
        sum = std::max(arr[a], sum+arr[a]);
        bestSum = std::max(bestSum,sum);
    }
    return bestSum;
}

int main()
{
    int arr[] = {-1,2,4,-3,5,2,-5,2};

    cout<<"\n Max Sum Subarray n cube  = "<<maxsumn3(arr, 8)<<"\n";
    cout<<"\n Max Sum Subarray n square= "<<maxsumn2(arr, 8)<<"\n";
    cout<<"\n Max Sum Subarray n one   = "<<maxsumn1(arr, 8)<<"\n";


    return 0;
}
