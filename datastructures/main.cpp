#include <iostream>
#include <array>

#include "linkedlist.h"

using namespace std;

//#define BUILD_LINKED_LIST
#define BUILD_BST

#ifdef BUILD_LINKED_LIST
int main()
{
    ds::linkedlist<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);


    cout<<"\n"<<ll<<std::endl;

//    cout<<"\n last ele : "<<ll.at(3)<<"\n";



   // ll.recursiveReversePrint(ll.begin());

//    cout<<"\n The list contains 3 :"<<ll.contains(ll.begin(),3) << std::endl;
//    cout<<"\n The list contains 33 :"<<ll.contains(33);
    cout<<"\n The list middle is  :"<<ll.mid()->val;

    //make the list loop back

    ds::node<int>* temp = ll.nodeAt(4);

//    temp->val = 3;
    ll.end()->next = temp;

//    if(ll.end())
    cout<<"\nLoop :: "<<ll.llistHasLoop(ll.begin());
    cout<<"\nLoop :: "<<ll.findBeginofLoop(ll.begin());
    cout<<"\nLoop Length :: "<<ll.lengthOfLoop(ll.begin());
    cout<<"\n done\n"<<"\n";



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

#endif


#ifdef BUILD_BST

#include "bst.h"

int main()
{
    ds::BST<int> tree;
    tree.add(12);
    tree.add(13);
    tree.add(11);
    tree.add(2);
    tree.add(5);
    tree.add(14);
    tree.add(10);
    tree.add(6);
    tree.add(4);
    tree.add(1);
    tree.add(7);
    tree.add(8);
//    tree.add(17);
    tree.add(16);
    tree.add(15);
    tree.add(16);
    tree.add(17);
    cout<<"\nBST \n";

    tree.printBST();

    std::cout<<"\n\n\n";
    tree.inOrderTraversalRec(tree.getRoot());
    std::cout<<"\n\n\n";
    tree.preOrderTraversalRec(tree.getRoot());
    std::cout<<"\n\n\n";
    tree.postOrderTraversalRec(tree.getRoot());
    std::cout<<"\n\n";

//    ds::bstNode<int>* v= tree.search(10,tree.getRoot());

    std::cout<<"Val at node : "<<tree.search(-10,tree.getRoot()) <<"\n\n";

}

#endif
