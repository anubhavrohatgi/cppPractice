#include <iostream>
#include <algorithm>
#include <deque>


using namespace std;

//sliding window
void slide(int arr[], size_t n, size_t k) {
    std::deque<int> dq;

    for(int i = 0; i < n; ++i){

        if(dq.size() == k) {

            std::string s;
            int mx = std::numeric_limits<int>::min();
//            for(auto a : dq ){
//                s.append(std::to_string(a));
//                s.append(" ");
//                mx = (a >= mx)? a : mx;
//            }
            mx = *std::max_element(dq.begin(),dq.end());
//            cout<<mx<<" ";
            cout<<"At n = k :::: "<<s<<"------"<<mx<<endl;

//            cout<<"Print yay : "<<dq.at(0)<<std::endl;
            dq.pop_front();
            dq.push_back(arr[i]);

            if(i == (n-1)) {
//                s.clear();
                int mx = std::numeric_limits<int>::min();

//                for(auto a : dq ){
//                    s.append(std::to_string(a));
//                    s.append(" ");
//                    mx = (a >= mx)? a : mx;
//                }
                mx = *std::max_element(dq.begin(),dq.end());
                cout<<"At n = k :::: "<<s<<"--------"<<mx<<endl;
//                cout<<mx<<" ";
                break;
            }
        } else {
            dq.push_back(arr[i]);
//            cout<<"Push : "<<arr[i]<<endl;
        }
    }
    std::cout<<std::endl;
}

int main()
{
//    int arr[] {1,2,3,4,5,6,7,11,2,3,4};
    int arr[] {3,4,6,3,4};
    slide(arr,5,2);

    return 0;
}
