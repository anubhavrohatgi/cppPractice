#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include <error.h>
#include <unordered_set>

#include "dsexceptions.h"

namespace ds {

// Node structure for singly linked list
template <typename T>
struct node {
    T val;
    node* next;
    node(const T& data) {
        val = data;
        next = nullptr;
    }
};


template <class T>
class linkedlist
{
public:
    linkedlist();
    ~linkedlist();

    /**
     * @brief push_back Push the new value to the end of list
     * @param val Input value to be pushed
     */
    void push_back(const T& val);


    /**
     * @brief push_front Push the new value to the beginning of the list
     * @param val
     */
    void push_front(const T& val);


    /**
     * @brief size Outputs the total size of the list
     *      Validates by traversing through the list
     * @return Output Size
     */
    size_t size() const;


    /**
     * @brief sizerec Outputs the total size of the list
     *      Validates by traversing through the list
     *      Recursive function
     * @nheadptr Pointer to the current node
     * @return Output Size
     */
    size_t sizerec(node<T>* nheadptr);


    /**
     * @brief length Outputs the size of the list. Doesnt validate by traversing the
     *      list, instead polls the lengthKeeper variable
     * @return Output Size
     */
    size_t length() const;

    /**
     * @brief empty Checks if the list is empty
     * @return Results true if the list is empty
     */
    bool empty() const;


    /**
     * @brief clear Clear the contents of the list
     */
    void clear();

    /**
     * @brief insert Inserts the value int the list at the supplied index
     * @param val Input data value
     * @param index Input index where the value is inserted
     */
    void insert(const T& val, size_t index);


    /**
     * @brief erase Erases the element at the given index
     * @param index Input index
     */
    void erase(size_t index);


    /**
     * @brief begin Returns the pointer to the head node
     * @return
     */
    node<T>* begin();


    /**
     * @brief end Returns the pointer to the tail node of the linked list
     * @return
     */
    node<T>* end();


    /**
     * @brief mid Mid of the linked list. Dones using a fast and a slow pointer
     * @return middle node of the linked list
     */
    node<T>* mid();

    /**
     * @brief operator << Overloaded output stream which outputs the data in the ostream
     * @param out Ostream reference that will be written to.
     * @param lst Input list being referenced
     * @return
     */
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const linkedlist<U>& lst);


    /**
     * @brief operator [] Allows update of the data by providing reference to the data value pointed
     *      at by the index
     * @param index Input index at which the value resides
     * @return
     */
    T& operator[](size_t index);


    /**
     * @brief at Does not allow modification of the value pointed to at by the supplied index
     * @param index Input index value
     * @return
     */
    T at(size_t index) const;


    /**
     * @brief nodeAt Returns the pointer node for which the index is supplied
     * @param index Input index for which the node pointer will be returned
     * @return pointer node
     */
    node<T>* nodeAt(size_t index);

    /**
     * @brief contains Checks if the list contains the input element
     *      iterative solution
     * @param val Input value to be searched
     * @return true if present
     */
    bool contains(const T& val);

    /**
     * @brief contains Checks if the list contains the input element
     *      Recursive Solution
     * @param curr current node
     * @param val input value to be found
     * @return true if found
     */
    bool contains(node<T>* curr, const T& val);

    /**
     * @brief reverse Reverses the linked list
     */
    void reverse();


    /**
     * @brief recursiveReversePrint Print the singly linked list in reverse order
     *      without actually reversing the list. This is a recursive fn.
     *
     * @param head Input pointer to the head of the SLL
     */
    void recursiveReversePrint(node<T>* head);


    /**
     * @brief removeDuplicates Removes duplicate elements using an unordered set
     */
    void removeDuplicates();


    /**
     * @brief nthNodefromEnd Gets the nth node from the end of the linked list
     *  I could have done it using the tailptr, but the problem statement asks
     *  to iterate over without the tailptr information in the priori.
     * @param head Input head ptr
     * @param n Input location nth.
     * @return Pointer to the nth node
     */
    node<T>* nthNodefromEnd(size_t n);


    /**
     * @brief llistHasLoop Checks if the linked list has loop
     * @param head Input head node
     * @return true if loop found
     */
    bool llistHasLoop(node<T>* head);


    /**
     * @brief findBeginofLoop Outputs the node value of the begining node of loop
     * @param head Input headptr
     * @return Output value
     */
    T findBeginofLoop(node<T>* head);


    /**
     * @brief lengthOfLoop Finds the length of the loop
     * @param head Input headptr
     * @return length of the loop
     */
    size_t lengthOfLoop(node<T>* head);

private:
    node<T>* headptr;
    node<T>* tailptr;
    size_t lengthKeeper;
};



//===========================================================================
//================ SINGLY LINKED LIST IMPLEMENTATION ========================
//===========================================================================


template <typename T>
linkedlist<T>::linkedlist()
{
    headptr = nullptr;
    tailptr = nullptr;
    lengthKeeper = 0;
}

template <typename T>
linkedlist<T>::~linkedlist()
{
    clear();
}


template <typename T>
void linkedlist<T>::clear()
{
    if(!empty()) {
        while(headptr != nullptr) {
             node<T>* tmp = headptr->next;
             delete headptr;
             headptr = tmp;
             tailptr = nullptr;
         }
        lengthKeeper = 0;
    }
}

template <typename T>
bool linkedlist<T>::empty() const
{
    if(headptr == nullptr && tailptr == nullptr)
        return true;
    else
        return false;
}


template <typename T>
size_t linkedlist<T>::size() const
{
    if(headptr == nullptr && tailptr == nullptr)
        return 0;
    else {
        size_t count = 0;
        node<T>* current = headptr;
        while(current!=nullptr){
            count++;
            current = current->next;
        }        
        return count;
    }
}


template <typename T>
size_t linkedlist<T>::sizerec(node<T>* nheadptr)
{
    if(nheadptr == nullptr) {
        return 0;
    } else {
        return 1 + sizerec(nheadptr->next);
    }
}


template <typename T>
size_t linkedlist<T>::length() const
{
    return lengthKeeper;
}

template <typename T>
node<T>* linkedlist<T>::begin()
{
    return headptr;
}


template <typename T>
node<T>* linkedlist<T>::end()
{
    return tailptr;
}

template <typename T>
T linkedlist<T>::at(size_t index) const
{
    if(headptr == nullptr && tailptr == nullptr)
        throw dsexceptions::FAIL_ACCESS;
    else if((index >= lengthKeeper) || (index < 0)) {
        throw dsexceptions::OUT_OF_BOUNDS;
    } else {
        size_t count = 0;
        node<T>* current = headptr;
        while(current!=nullptr){
            if(index == count) {
                return current->val;
            } else {
                count++;
                current = current->next;
            }
        }
        throw dsexceptions::OUT_OF_BOUNDS;
    }
}


template <typename T>
node<T>* linkedlist<T>::nodeAt(size_t index)
{
    if(headptr == nullptr && tailptr == nullptr)
        throw dsexceptions::FAIL_ACCESS;
    else if((index >= lengthKeeper) || (index < 0)) {
        throw dsexceptions::OUT_OF_BOUNDS;
    } else {
        size_t count = 0;
        node<T>* current = headptr;
        while(current!=nullptr){
            if(index == count) {
                return current;
            } else {
                count++;
                current = current->next;
            }
        }
        throw dsexceptions::OUT_OF_BOUNDS;
    }
}


template <typename T>
T& linkedlist<T>::operator[](size_t index)
{
    if(headptr == nullptr && tailptr == nullptr)
        throw dsexceptions::FAIL_ACCESS;
    else if ((index >= lengthKeeper) || (index <0)) {
        throw dsexceptions::OUT_OF_BOUNDS;
    } else {
        return nodeAt(index)->val;
    }
}




template <typename T>
void linkedlist<T>::push_back(const T& val)
{
    if(empty()) {
        node<T>* newPtr = new (std::nothrow) node<T>(val);
        headptr = newPtr;
        tailptr = newPtr;
    } else {
        node<T>* newPtr = new (std::nothrow) node<T>(val);
        tailptr->next = newPtr;
        tailptr = newPtr;
    }
    lengthKeeper +=1;
}



template <typename T>
void linkedlist<T>::push_front(const T& val)
{
    if(empty()) {
        node<T>* newPtr = new (std::nothrow) node<T>(val);
        headptr = newPtr;
        tailptr = newPtr;
    } else {
        node<T>* newPtr = new (std::nothrow) node<T>(val);
        newPtr->next = headptr;
        headptr = newPtr;
    }
    lengthKeeper +=1;
}


template <typename T>
void linkedlist<T>::insert(const T& val,size_t index)
{
    if(empty()) {
        throw INVALID_INDEX;
    } else {
        // insert the node at the given index
        if((index >=0) && (index < length())){
            if(index == 0) { //insert at beginning
                push_front(val);
            }else if(index == lengthKeeper-1) { //insert at end
                push_back(val);
            }else { //insert in between
                node<T>* newPtr = new node<T>(val);
                node<T>* current = nodeAt(index);
                node<T>* prev = nodeAt(index-1);
                prev->next = newPtr;
                newPtr->next = current;
            }
            lengthKeeper += 1;
        } else {
            throw dsexceptions::INVALID_INDEX;
        }
    }
}


template <typename T>
void linkedlist<T>::erase(size_t index)
{
    if(empty()) {
        throw dsexceptions::INVALID_INDEX;
    } else {
        // delete the node at the given index
        if((index >=0) && (index < length())){

            if(length() == 1) { //if only one element remaining

                //reset the lengthKeeper in the clear fn
                clear();

            } else if(index == 0) { //delete at beginning

                node<T>* newcur = headptr->next;
                delete headptr;
                headptr = newcur;
                lengthKeeper -= 1;

            } else if((index == lengthKeeper-1) && (lengthKeeper > 1)) { //delete at end

                node<T>* newcur = nodeAt(lengthKeeper-2);
                newcur->next = nullptr;
                delete tailptr;
                tailptr = newcur;
                lengthKeeper -= 1;

            }else { //delete in between
                node<T>* temp = nodeAt(index);
                node<T>* prev = nodeAt(index-1);
                prev->next = temp->next;
                delete temp;
                lengthKeeper-=1;
            }
        } else {
            throw dsexceptions::INVALID_INDEX;
        }
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const linkedlist<T>& lst)
{
    node<T>* current = lst.headptr;
    while(current!=nullptr) {
        out<<current->val<<" ";
        current = current->next;
    }
    return out;
}


template <typename T>
bool linkedlist<T>::contains(const T& val)
{
    if(empty()) {
        return false;
    } else {
        node<T>* current = headptr;
        while(current != nullptr) {
            if(val == current->val){
                return true;
            }
            current = current->next;
        }
        return false;
    }
}


template <typename T>
bool linkedlist<T>::contains(node<T>* curr, const T& val)
{
    if(curr == nullptr) {
        return false;
    }

    if(val == curr->val)
        return true;

    return contains(curr->next,val);
}


template <typename T>
void linkedlist<T>::reverse()
{
    if(!empty()) {
        node<T>* curr = headptr;
        node<T>* prev = nullptr;
        node<T>* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tailptr = headptr;
        tailptr->next = nullptr;
        headptr = prev;

    }
}


template <typename T>
node<T>* linkedlist<T>::mid()
{
    if(empty())
        return nullptr;

    node<T>* fastPtr = headptr;
    node<T>* slowPtr = headptr;

    while(fastPtr != nullptr && fastPtr->next !=nullptr){
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr;
}



template <typename T>
void linkedlist<T>::removeDuplicates()
{
    if(empty())
        return;

    std::unordered_set<T> seen;

    node<T>* curr = headptr;
    node<T>* prev = nullptr;

    while (curr != nullptr)
    {
        // If current value is seen before
        if (seen.find(curr->val) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->val);
            prev = curr;
        }
        curr = prev->next;
    }
}


template <typename T>
void linkedlist<T>::recursiveReversePrint(node<T>* head)
{
    if(head == nullptr)
        return;

    recursiveReversePrint(head->next);
    std::cout<<head->val<<std::endl;
}



template <typename T>
node<T>* linkedlist<T>::nthNodefromEnd(size_t n)
{
    if(headptr == nullptr)
        return nullptr;

    size_t len = 0;
    node<T>* cur = headptr;
    while(cur!= nullptr){
        len++;
        cur = cur->next;
    }

    if(n > len){
        throw dsexceptions::INVALID_INDEX;
    }

    cur = headptr;
    //now nth node in demand is at len -n +1
    for(size_t k =0; k < (len-n-1); k++){
        cur = cur->next;
    }

    return cur;
}


template <typename T>
bool linkedlist<T>::llistHasLoop(node<T>* head)
{
    node<T>* fastPtr = head;
    node<T>* slowPtr = head;

    if(head == nullptr){
        return false;
    }

    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr==fastPtr)
            return true;
    }
    return false;
}

template <typename T>
T linkedlist<T>::findBeginofLoop(node<T>* head){

    if(head == nullptr)
        return 0;

    node<T>* fastPtr = headptr;
    node<T>* slowPtr = headptr;

    bool loopExists = false;
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr) {
            loopExists=true;
            break;
        }
    }

    if(loopExists) {
        slowPtr = head;
        while(slowPtr!=fastPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr->val;
    } else {
        return 0;
    }
}

template <typename T>
size_t linkedlist<T>::lengthOfLoop(node<T>* head) {
    if(head == nullptr)
        return 0;

    size_t len = 0;
    bool loopExists = false;
    node<T>* slowPtr = head;
    node<T>* fastPtr = head;

    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr){
            loopExists = true;
            break;
        }
    }


    if(loopExists){
        fastPtr = fastPtr->next;
        while(slowPtr != fastPtr){
            len++;
            fastPtr = fastPtr->next;
        }
    }
    return  len;
}

}//end of namespace ds

#endif // LINKEDLIST_H
