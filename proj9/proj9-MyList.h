// File: proj9-MyList.h
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 9
// Due Date: 11/20/2023

// Date Modified: 11/9/2023
//     -File created
// Date Modified: 11/14/2023
//     -File finished
//  Contains the header and implementation of the MyList class

#ifndef PROJECT9_PROJ9_MYLIST_H
#define PROJECT9_PROJ9_MYLIST_H

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

template <class T>
class MyList : public ContainerIfc <T> {
public:
    /*
     *MyList
     *
     *This function is the default constructor
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: none
     *    reference parameters: none
     *    stream: none
    */
    MyList();

    /*
     *~MyList
     *
     *This function is the destructor
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: none
     *    reference parameters: none
     *    stream: none
    */
    ~ MyList();

    /*
     *MyList
     *
     *This function is the copy constructor
     *
     *Parameters:
     *    a: const MyList reference
     *
     *Output:
     *    return: none
     *    reference parameters: a
     *    stream: none
    */
    MyList(const MyList&);

    /*
     *operator =
     *
     *This function is the overloaded assignment operator
     *
     *Parameters:
     *    a: const MyList reference
     *
     *Output:
     *    return: *this
     *    reference parameters: a
     *    stream: none
    */
    MyList <T>& operator = (const MyList&);

    /*
     *pushFront
     *
     *This function stores data element e in a new Node and adds the
     * Node to the front of a data structure
     *
     *Parameters:
     *    e: type T
     *
     *Output:
     *    return: a reference to itself
     *    reference parameters: none
     *    stream: none
    */
    MyList <T>& pushFront(T);

    /*
     *pushBack
     *
     *This function stores data element e in a new Node and adds the
     * Node to teh rear of a data structure
     *
     *Parameters:
     *    e: type T
     *
     *Output:
     *    return: a reference to itself
     *    reference parameters: none
     *    stream: none
    */
    MyList <T>& pushBack(T);

    /*
     *popFront
     *
     *This function removes a data element from the front of the data structure
     *
     *Parameters:
     *    e: reference to type T
     *
     *Output:
     *    return: a reference to itself
     *    reference parameters: e
     *    stream: none
    */
    MyList <T>& popFront(T&);

    /*
     *popBack
     *
     *This function removes a data element from the rear of the data structure
     *
     *Parameters:
     *    e: a reference to type T
     *
     *Output:
     *    return: a reference to itself
     *    reference parameters: e
     *    stream: none
    */
    MyList <T>& popBack(T&);

    /*
     *getSize
     *
     *This function returns the number of Nodes currently in the linked MyList
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: an integer value representing the number of elements in the MyList
     *    reference parameters: none
     *    stream: none
    */
    int getSize();

    /*
     *isEmpty
     *
     *This function returns the state information about the list
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: true if the MyList is empty false otherwise
     *    reference parameters: none
     *    stream: none
    */
    bool isEmpty();

    /*
     *front
     *
     *This function returns a copy of the first data item in the linked list
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the first data item in the linked list
     *    reference parameters: none
     *    stream: none
    */
    T front();

    /*
     *back
     *
     *This function returns a copy of the last data item in the linked list
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the last data item in the linked list
     *    reference parameters: none
     *    stream: none
    */
    T back();

    /*
     *operator[]
     *
     *This function returns a reference to data element ndx in the linked list
     *
     *Parameters:
     *    ndx: integer
     *
     *Output:
     *    return: a reference to the data element ndx in the linked list
     *    reference parameters: none
     *    stream: none
    */
    T& operator [](int);

    /*
     *erase
     *
     *This function removes all nodes from MyList
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void erase();
//    MyList<T>& enqueue(T);
//    MyList<T>& dequeue(T&);// throws BADINDEX

protected:
    Node<T> *head;
};

//template <class T>
//MyList<T>& MyList<T>::enqueue(T e){
//    return this->pushFront(e);
//}
//
//template <class T>
//MyList<T>& MyList<T>::dequeue(T& e){
//    if(isEmpty()){
//        throw BADINDEX();
//    }
//    return this->popBack(e);
//}

template <class T>
MyList<T>::MyList(){
    this->head = nullptr;
}

template <class T>
MyList<T>::~ MyList(){
    while(this->head != nullptr){
        Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->head = nullptr;
}

template <class T>
MyList<T>::MyList(const MyList& other){
    this->head = nullptr;
    if(other.head != nullptr){
        this->head = new Node<T>(other.head->data);
        Node<T> *temp = other.head->next;
        Node<T> *curr = this->head;

        while(temp != nullptr){
            curr->next = new Node<T>(temp->data);
            curr = curr->next;
            temp = temp->next;
        }
    }
}

template <class T>
MyList <T>& MyList<T>::operator = (const MyList& other){
    this->erase();

    //this->head = nullptr;
    if(this != &other){
        if(other.head != nullptr){
            this->head = new Node<T>(other.head->data);

            Node<T> *curr = this->head;
            Node<T> *temp = other.head->next;
            while(temp != nullptr){
                curr->next = new Node<T>(temp->data);
                curr = curr->next;
                temp = temp->next;
            }
        }
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::pushFront(T e){
    Node<T> *temp = new Node<T>(e);

    if(isEmpty()){
        this->head = temp;
    }
    else{
        temp->next = this->head;
        this->head = temp;
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::pushBack(T e){
    Node<T> *temp = new Node<T>(e);

    if(isEmpty()){
        this->head = temp;
    }
    else{
        Node<T> *curr = this->head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = temp;
    }
    return *this;
}

template <class T>
MyList <T>& MyList<T>::popFront(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }

    Node<T> *temp = this->head;
    e = temp->data;
    this->head = this->head->next;
    delete temp;

    return *this;
}

template <class T>
MyList <T>& MyList<T>::popBack(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }

    Node<T> *temp = this->head;
    Node<T> *prev = nullptr;
    while(temp->next != nullptr){
        prev = temp;
        temp = temp->next;
    }
    e = temp->data;

    if(prev == nullptr){
        this->head = nullptr;
    }
    else{
        prev->next = nullptr;
    }
    //e = temp->data;
    delete temp;

    return *this;
}

template <class T>
int MyList<T>::getSize(){
    int size = 0;
    Node<T> *temp = this->head;

    while(temp != nullptr){
        temp = temp->next;
        size++;
    }
    return size;
}

template <class T>
bool MyList<T>::isEmpty(){
    return this->head == nullptr;
}

template <class T>
T MyList<T>::front(){
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->head->data;
}

template <class T>
T MyList<T>::back(){
    if(isEmpty()){
        throw BADINDEX();
    }

    Node<T> *temp = this->head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
T& MyList<T>::operator [](int ndx){
    if(isEmpty() || ndx >= this->getSize()){
        throw BADINDEX();
    }

    Node<T> *temp = this->head;
    for(int i = 0; i < ndx; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void MyList<T>::erase(){
    while(!isEmpty()){
        Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->head = nullptr;
}

#endif //PROJECT9_PROJ9_MYLIST_H
