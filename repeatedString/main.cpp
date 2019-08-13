#include <bits/stdc++.h>

using namespace std;

//Lilah has a string, , of lowercase English letters that she repeated infinitely many times.

//Given an integer, , find and print the number of letter a's in the first  letters of Lilah's infinite string.

//For example, if the string  and , the substring we consider is , the first  characters of her infinite string. There are  occurrences of a in the substring.

//Function Description

//Complete the repeatedString function in the editor below. It should return an integer representing the number of occurrences of a in the prefix of length  in the infinitely repeating string.

//repeatedString has the following parameter(s):

//s: a string to repeat
//n: the number of characters to consider
//Input Format

//The first line contains a single string, .
//The second line contains an integer, .


// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    if(s.size() > n) {
        return std::count(s.begin(),s.end()-(s.size()-n),'a');
    } else if(s.size() == n){
        return std::count(s.begin(),s.end(),'a');
    } else {
        int bal = n%s.size();
        long base = std::count(s.begin(),s.end(),'a');
        return (base*(n-bal)/s.size()) + std::count(s.begin(),s.begin()+bal, 'a');
    }
}

int main()
{
    long n = 11;
    std::string s = "aaabab";

    std::cout<<"\n Repeats : :: "<<repeatedString(s,n)<<std::endl;


    return 0;
}
