#include <iostream>
#include <memory>
#include "singleresponsibility.h"

using namespace std;

int main()
{

    //Single Responsibility ===========================
    notes nts;
    nts.setTitle("Anubhav");
    nts.addnote("Great tutorial 1312");

    storage s;
    if(s.save(nts,"/home/anubhav/Desktop/testing1.txt")) {
        cout<<"\nSaved\n";
    } else {
        return -1;
    }

    notes nt;
    s.load(nt,"/home/anubhav/Desktop/testing1.txt");

    cout<<"\n Title : "<<nt.getTitle()<<std::endl;
    cout<<"\n Data : "<<nt.getData()<<std::endl;


    //OPEN-CLOSED ====================================




    return 0;
}
