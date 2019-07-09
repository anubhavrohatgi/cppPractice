#include <iostream>
#include <array>
#include "array.h"

#include "linkedlist.h"

using namespace std;

int main()
{
    ds::linkedlist<int> ll;
    ll.push_back(1);
    ll.push_back(31);
    ll.push_back(3);
    ll.push_back(4);
//    ll.push_back(5);

    cout<<"\n"<<ll<<std::endl;

    ll.recursiveReversePrint(ll.begin());

//    cout<<"\n The list contains 3 :"<<ll.contains(ll.begin(),3) << std::endl;
//    cout<<"\n The list contains 33 :"<<ll.contains(33);
    cout<<"\n The list middle is  :"<<ll.mid()->val;

//    ll[0] = 44;

//    cout<<"\nnew as updated"<<ll<<std::endl;

//    ll.reverse();
//    cout<<"\nReversed  List :: "<<ll;

//     cout<<"\nReversed  List tail  :: "<<ll.end()->val;

//    std::cout<<"Size before = "<<ll.size();
//    std::cout<<"\nlength before = "<<ll.length();

//    std::cout<<"\nNode at index 2 = "<<ll.nodeAt(2)->val;
//    std::cout<<"\nValue at index 2 = "<<ll.at(2)<<std::endl;


//    ll.insert(66,2);
//    cout<<"\nnow "<<ll<<std::endl;
//    std::cout<<"Size after now = "<<ll.length() <<std::endl;


//    ll.erase(0);
//    cout<<"\nnow1 : "<<ll<<std::endl;
//    cout<<"\nlength now1 : "<<ll.length()<<std::endl;

//    ll.erase(1);
//    cout<<"\nnow2 : "<<ll<<std::endl;
//    cout<<"\nlength now2 : "<<ll.length()<<std::endl;

//    ll.erase(2);
//    cout<<"\nnow3 : "<<ll<<std::endl;
//    cout<<"\nlength now3 : "<<ll.length()<<std::endl;
//    cout<<"\nHead now3 : "<<ll.begin()->val<<std::endl;
//    cout<<"\nTail now3 : "<<ll.end()->val<<std::endl;

//    ll.erase(1);
//    cout<<"\nnow4 : "<<ll<<std::endl;
//    cout<<"\nlength now4 : "<<ll.length()<<std::endl;

//    ll.erase(0);
//    cout<<"\nnow5 : "<<ll<<std::endl;
//    cout<<"\nlength now5 : "<<ll.length()<<std::endl;

////    cout<<"\n ::: "<<ll.begin()->val;

////    cout<<"\nlength now "<<ll.length()<<std::endl;


//    ll.clear();

//    std::cout<<"Size after = "<<ll.size() <<std::endl;
//    std::cout<<"length after = "<<ll.length()<<std::endl;
    return 0;
}
