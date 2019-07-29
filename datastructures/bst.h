#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <error.h>

#include <stack>



namespace ds {

template <typename T>
struct node {
    T data;
    node* left;
    node* right;

    node(const T& val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BST {
public:
    BST();
    ~BST();

    bool empty();

    void clear();

    void add(const T& val);
    void addImpl(node<T>** root, const T& val);


private:
    node<T>* root;
    size_t maxHeight;
};


template <typename T>
BST<T>::BST(){
    root = nullptr;
    maxHeight = -1;
}

template <typename T>
BST<T>::~BST<T>()
{
    clear();
}

template <typename T>
void BST<T>::add(const T& val){
    add(&root,val);
}

template <typename T>
void BST<T>::addImpl(node<T>** root,const T& val) {
    if(root == nullptr){
        root = new node<T>(val);
    } else {
        if(val <= root->data) {
            //go left

        } else {
            //go right
        }
    }
}


} //end of namepspace ds

#endif // BST_H
