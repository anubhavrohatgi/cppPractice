#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <error.h>

#include <stack>



namespace ds {

template <typename T>
struct bstNode {
    T data;
    bstNode* left;
    bstNode* right;

    bstNode(const T& val) {
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

    bstNode<T>* getRoot() const;

    void clear();
    bstNode<T> *clearImpl(bstNode<T> *base);

    void add(const T& val);
    void addImpl(bstNode<T>** base, const T& val);

    void printBST();
    void printBSTImpl(const std::string& prefix, bstNode<T> **node, bool isLeft);

    void inOrderTraversalRec(bstNode<T>* base);
    void inOrderTraversal(bstNode<T>* base);

    void postOrderTraversalRec(bstNode<T>* base);
    void postOrderTraversal(bstNode<T>* base);

    void preOrderTraversalRec(bstNode<T>* base);
    void preOrderTraversal(bstNode<T>* base);

    bool search(const T& val,bstNode<T>* base);

    int height(bstNode<T>* base);

    bstNode<T> *findMin(bstNode<T>* base) const;
    bstNode<T> *findMax(bstNode<T>* base) const;

private:
    bstNode<T>* root;
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
void BST<T>::clear()
{
    if(root){
        root = clearImpl(root);
    }
}

template <typename T>
bstNode<T>* BST<T>::clearImpl(bstNode<T>* base)
{
    if(base == nullptr)
        return nullptr;

    clearImpl(base->left);
    clearImpl(base->right);
//    std::cout<<"\nPost Order "<<base->data;
    delete base;
    return nullptr;
}

template <typename T>
bstNode<T>* BST<T>::getRoot() const
{
    return root;
}


template <typename T>
void BST<T>::add(const T& val){
    addImpl(&root,val);
}

template <typename T>
void BST<T>::addImpl(bstNode<T>** base,const T& val) {
    if(*base == nullptr){
        *base = new bstNode<T>(val);
    } else {
        if(val < (*base)->data) {
            //go left
            addImpl(&((*base)->left),val);
        } else if(val > (*base)->data){
            //go right
            addImpl(&((*base)->right),val);
        } else {
            std::cerr<<"\nDuplicate value, rejecting";
        }
    }
}


template <typename T>
void BST<T>::printBSTImpl(const std::string& prefix, bstNode<T>** node, bool isLeft)
{
    if( *node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << (*node)->data << std::endl;

        // enter the next tree level - left and right branch
        printBSTImpl( prefix + (isLeft ? "│   " : "    "), &((*node)->left), true);
        printBSTImpl( prefix + (isLeft ? "│   " : "    "), &((*node)->right), false);
    }
}

template <typename T>
void BST<T>::printBST()
{
    printBSTImpl("", &root, false);
}


template <typename T>
void BST<T>::inOrderTraversalRec(bstNode<T>* base)
{
    if(base != nullptr) {
        inOrderTraversalRec(base->left);
        std::cout<<base->data<<"  ";
        inOrderTraversalRec(base->right);
    }
}


template <typename T>
void BST<T>::preOrderTraversalRec(bstNode<T>* base)
{
    if(base != nullptr) {
        std::cout<<base->data<<"  ";
        preOrderTraversalRec(base->left);
        preOrderTraversalRec(base->right);
    }
}



template <typename T>
void BST<T>::postOrderTraversalRec(bstNode<T>* base)
{
    if(base != nullptr) {
        postOrderTraversalRec(base->left);
        postOrderTraversalRec(base->right);
        std::cout<<base->data<<"  ";
    }
}


template <typename T>
bool BST<T>::search(const T& val,bstNode<T>* base)
{
    if(base!=nullptr)
    {
        if(val==base->data)
            return true;
        if(val<base->data)
            return search(val, base->left);
        else
            return search(val, base->right);
    }
    else
        return false;
}

template <typename T>
int BST<T>::height(bstNode<T>* base)
{
    if(base == nullptr)
        return  -1;
    else{
        return std::max(height(base->left),height(base->right)) + 1;
    }
}


template <typename T>
bstNode<T>* BST<T>::findMin(bstNode<T>* base) const
{
    if(base == nullptr)
        return nullptr;
    else if(base->left == nullptr){
        return base;
    } else {
        return findMin(base->left);
    }
}

template <typename T>
bstNode<T>* BST<T>::findMax(bstNode<T>* base) const
{
    if(base == nullptr)
        return nullptr;
    else if(base->right == nullptr){
        return base;
    } else {
        return findMax(base->right);
    }
}

template <typename T>
void BST<T>::preOrderTraversal(bstNode<T>* base)
{
    if(base == nullptr)
        return;

    std::stack<bstNode<T>*> s;
    s.push(base);

    while(!s.empty()) {

        bstNode<T>* node = s.top();
        std::cout<<node->data<<"  ";
        s.pop();
        if(node->right)
            s.push(node->right);
        if(node->left)
            s.push(node->left); //this is the last push since
        //we want the left to be read out first
        //hence this will be at tp of the stack
    }
}


template <typename T>
void BST<T>::inOrderTraversal(bstNode<T>* base)
{
    if(base == nullptr)
        return;

    std::stack<bstNode<T>*> s;
    bstNode<T>* cur = base;

    while( cur != nullptr || !s.empty()) {

        while (cur != nullptr) {
            s.push(cur);
            cur=cur->left;
        }

        cur = s.top();
        std::cout<<cur->data<<"  ";
        s.pop();
        cur = cur->right;
    }
}


template <typename T>
void BST<T>::postOrderTraversal(bstNode<T>* base)
{
    if(base == nullptr)
        return;

    std::stack<bstNode<T>*> s;
    bstNode<T>* cur = base;
    bstNode<T>* prev = nullptr;

    do {
        //push left
        while(cur != nullptr){
            s.push(cur);
            cur = cur->left;
        }

        //push right
        while(cur == nullptr && !s.empty()){
            cur = s.top();
            if(cur->right == nullptr || cur->right == prev) {
                std::cout<<cur->data<<"  ";
                s.pop();
                prev = cur;
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
    } while(!s.empty());
}

} //end of namepspace ds

#endif // BST_H
