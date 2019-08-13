#include <bits/stdc++.h>

using namespace std;

//John works at a clothing store. He has a large pile of socks that he must pair by color for sale. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.

//For example, there are  socks with colors . There is one pair of color  and one of color . There are three odd socks left, one of each color. The number of pairs is .

//Function Description

//Complete the sockMerchant function in the editor below. It must return an integer representing the number of matching pairs of socks that are available.

//sockMerchant has the following parameter(s):

//n: the number of socks in the pile
//ar: the colors of each sock
//Input Format

//The first line contains an integer , the number of socks represented in .
//The second line contains  space-separated integers describing the colors  of the socks in the pile.

//Constraints

// where
//Output Format

//Return the total number of matching pairs of socks that John can sell.


vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(size_t n, vector<int> ar) {
    int npairs=0;
    std::unordered_set<int> lut;
    for(auto i : ar){
        if(lut.empty()){
            //push element
            lut.insert(i);
        } else {
            auto it = lut.find(i);

            if(it!=lut.end()){
                lut.erase(it);
                npairs++;
            } else {
                lut.insert(i);
            }

        }
    }
    return npairs;
}

int main()
{

    std::vector<int> ar {1,2,1,1,2,3,1,2,5};



    int result = sockMerchant(ar.size(), ar);


    std::cout<<"\n No of pairs : "<<result<<std::endl;



    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
