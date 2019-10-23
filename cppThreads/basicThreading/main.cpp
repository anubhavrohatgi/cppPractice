// Includes
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>


//thread constructor accepts the following arguments in its constructor

//[1] Function Pointer
//[2] Function Objects or Functors
//[3] Lambda Function
//[4] Static/Non Static Member Functions


//[1] Function Pointer
void printMe() {
    for(int i =0; i < 10; ++i)
        std::cout<<"\n[FPTR] Printing "<<i<<std::endl;
}

void printMe_argument(std::string s){
    for(int i =0; i < 10; ++i)
        std::cout<<"\n[FPTR_ARG] Printing "<<s<<"  "<<i<<std::endl;
}

void printMe_argument_ref(std::string& s){
    s = "anu";
    for(int i =0; i < 10; ++i)
        std::cout<<"\n[FPTR_ARG_REF] Printing "<<s<<"  "<<i<<std::endl;
}


//[2] Function Objects

class WorkerThread1 {
public:
    void operator() () {
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[FUN_OBJ] Printing "<<i<<std::endl;
    }
};


class WorkerThread2 {
public:
    void operator() (std::string s) {
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[FUN_OBJ_ARG] Printing "<<s<<"  "<<i<<std::endl;
    }
};


class WorkerThread3 {
public:
    void operator() (std::string& s) {
        s = "anil";
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[FUN_OBJ_ARG_REF] Printing "<<s<<"  "<<i<<std::endl;
    }
};


//[4] Non Static Member function
class dowork1 {
public:
    void run() {
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[MEM_FUN] Printing "<<i<<std::endl;
    }
};

class dowork2 {
public:
    void run(std::string s) {
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[MEM_FUN_ARG] Printing "<<s<<"  "<<i<<std::endl;
    }
};


class dowork3 {
public:
    void run(std::string& s) {
        s= "gamma";
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[MEM_FUN_ARG_REF] Printing "<<s<<"  "<<i<<std::endl;
    }
};


class dowork4 {
public:
    static void run() {
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[MEM_FUN_STATIC] Printing "<<i<<std::endl;
    }
};

class dowork5 {
public:
    static void run(std::string s) {
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[MEM_FUN_ARG_STATIC] Printing "<<s<<"  "<<i<<std::endl;
    }
};


class dowork6 {
public:
    static void run(std::string& s) {
        s= "gammaStatic";
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[MEM_FUN_ARG_REF_STATIC] Printing "<<s<<"  "<<i<<std::endl;
    }
};


//main default thread
int main() {

    //[1]
    //create and fire thread using function pointer
    std::thread t1_fptr(printMe);

    //create and fire thread using function pointer with input argument
    std::thread t1_afptr(printMe_argument,"don");

    //create and fire thread using function pointer with input argument reference
    std::string str = "anubhav";
    std::thread t1_areffptr(printMe_argument_ref,std::ref(str));


    //[2]
    //create and fire thread using function object
    std::thread t2_fobj( (WorkerThread1()) );

    //create and fire thread using function object with input argument
    std::thread t2_afobj( (WorkerThread2()),"cat" );

    //create and fire thread using function object with input reference argument
    std::string str1 = "dog";
    std::thread t2_areffobj( (WorkerThread2()),str1 );



    //[3]
    //create and fire thread using lambda function
    std::thread t3_flambda([]{
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[FUN_LAMBDA] Printing "<<i<<std::endl;
    });


    //create and fire thread using lambda function with input
    std::string str2 = "alpha";
    std::thread t3_aflambda([str2](){
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[FUN_LAMBDA_CAP_ARG] Printing "<<str2<<"  "<<i<<std::endl;
    });


    //create and fire thread using lambda function with input reference
    std::thread t3_arefflambda([&str2](){
        str2 = "beta";
        for(int i =0; i < 10; ++i)
            std::cout<<"\n[FUN_LAMBDA_ARG_CAPT_ARG_REF] Printing "<<str2<<"  "<<i<<std::endl;
    });
//    std::cout<<"\n[Main] After LAMBDA String value = "<<str2<<std::endl;



    //[4] Non Static
    dowork1 d1;
    std::thread t4_nsmem(&dowork1::run,&d1);

    dowork2 d2;
    std::thread t4_nsmema(&dowork2::run,&d2,"beer");

    dowork3 d3;
    std::string str3 = "shama";
    std::thread t4_nsmemaref(&dowork3::run,&d3,std::ref(str3));


    //[4] Static
    std::thread t4_smem(&dowork4::run);
    std::thread t4_smema(&dowork5::run,"static");
    std::string str4 = "shama";
    std::thread t4_smemaref(&dowork6::run,std::ref(str4));


    //check if the thread is joinable or not
    if(t1_fptr.joinable())
        t1_fptr.join();

    if(t1_afptr.joinable())
        t1_afptr.join();

    if(t1_areffptr.joinable())
        t1_areffptr.join();

    if(t2_fobj.joinable())
        t2_fobj.join();

    if(t2_afobj.joinable())
        t2_afobj.join();

    if(t2_areffobj.joinable())
        t2_areffobj.join();


    if(t3_flambda.joinable())
        t3_flambda.join();

    if(t3_aflambda.joinable())
        t3_aflambda.join();

    if(t3_arefflambda.joinable())
        t3_arefflambda.join();

    if(t4_nsmem.joinable())
        t4_nsmem.join();

    if(t4_nsmema.joinable())
        t4_nsmema.join();

    if(t4_nsmemaref.joinable())
        t4_nsmemaref.join();

    if(t4_smem.joinable())
        t4_smem.join();
    if(t4_smemaref.joinable())
        t4_smemaref.join();
    if(t4_smemaref.joinable())
        t4_smemaref.join();

    std::cout<<"\n[Main] String value = "<<str<<std::endl;
    std::cout<<"\n[Main] After FOBJ String value = "<<str1<<std::endl;
    std::cout<<"\n[Main] After LAMBDA String value = "<<str2<<std::endl;
    std::cout<<"\n[Main] After Non Static String value = "<<str3<<std::endl;
    std::cout<<"\n[Main] After Static String value = "<<str4<<std::endl;

    std::cout<<"\n--Completed--\n";

    return EXIT_SUCCESS;
}
