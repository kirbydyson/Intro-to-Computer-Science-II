// File: proj10-MyVector.h
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 10
// Due Date: 12/04/2023

// Date Modified: 11/28/2023
//     -File created
// Date Modified: 11/28/2023
//     -File finished
// Contains the header and implementation of the MyVector class

#ifndef PROJ10_PROJ10_MYVECTOR_H
#define PROJ10_PROJ10_MYVECTOR_H

#include "proj10-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    /*
     *MyVector
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
    MyVector ();
    /*
     *~MyVector
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
    ~MyVector ();
    /*
     *MyVector
     *
     *This function is the copy constructor
     *
     *Parameters:
     *    other: const MyVector reference
     *
     *Output:
     *    return: none
     *    reference parameters: other
     *    stream: none
    */
    MyVector (const MyVector&);
    /*
     *operator =
     *
     *This function is the overloaded assignment operator
     *
     *Parameters:
     *    other: const MyVector reference
     *
     *Output:
     *    return: a reference to itself
     *    reference parameters: other
     *    stream: none
    */
    MyVector<T>& operator = (const MyVector&);
    /*
     *pushFront
     *
     *This function adds data element e to the front of the vector
     *
     *Parameters:
     *    e: type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: none
     *    stream: none
    */
    MyVector<T>& pushFront(T);
    /*
     *pushBack
     *
     *This function stores data element e in the end of the vector
     *
     *Parameters:
     *    e: type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: none
     *    stream: none
    */
    MyVector<T>& pushBack(T);
    /*
     *popFront
     *
     *This function removes a data element from the front of the data structure
     *
     *Parameters:
     *    e: reference to type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: e
     *    stream: none
    */
    MyVector<T>& popFront(T&); // throws BADINDEX
    /*
     *popBack
     *
     *This function removes a data element from the end of the data structure
     *
     *Parameters:
     *    e: reference to type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: e
     *    stream: none
    */
    MyVector<T>& popBack(T&);  // throws BADINDEX
    /*
     *front
     *
     *This function returns a copy of the first data item in the MyVector
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the object at the beginning of the array
     *    reference parameters: none
     *    stream: none
    */
    T  front();        // throws BADINDEX
    /*
     *back
     *
     *This function returns a copy of the last data item in MyVector
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the object at the end of the array
     *    reference parameters: none
     *    stream: none
    */
    T  back();        // throws BADINDEX
    /*
     *operator []
     *
     *This function returns a reference to data element n in MyVector
     *
     *Parameters:
     *    ndx: integer
     *
     *Output:
     *    return: a reference to the object stored at offset of n within data
     *    reference parameters: none
     *    stream: none
    */
    T&  operator [](int);   // throws BADINDEX
    /*
     *getSize
     *
     *This function returns the number of elements currently in the MyVector
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: an integer value representing the number of elements in the list
     *    reference parameters: none
     *    stream: none
    */
    int getSize();
    /*
     *isEmpty
     *
     *This function returns state information about the list
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: true if the MyVector is empty false otherwise
     *    reference parameters: none
     *    stream: none
    */
    bool isEmpty();
    /*
     *erase
     *
     *This function erases a vector
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

protected:
    T  *data;
    int size;
    int capacity;

    /*
     *grow
     *
     *This function increases the capacity of data by doubling the previous
     *value and allocating the appropriate memory for data
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void grow();
    /*
     *shiftRight
     *
     *This function shifts all values in the array one space to the right
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void shiftRight();
    /*
     *shiftLeft
     *
     *This function shifts all values in the array one space to the left
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void shiftLeft();
};

template <class T>
void MyVector<T>::grow(){
    this->capacity *= 2;
    T *temp = this->data;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; i++){
        this->data[i] = temp[i];
    }
    delete[] temp;
}

template <class T>
void MyVector<T>::shiftRight(){
    for(int i = this->size; i > 0; i--){
        this->data[i] = this->data[i - 1];
    }
}

template <class T>
void MyVector<T>::shiftLeft(){
    for(int i = 0; i < this->size - 1; i++){
        this->data[i] = this->data[i + 1];
    }
}

template <class T>
MyVector<T>::MyVector (){
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
}

template <class T>
MyVector<T>::~MyVector (){
    delete[] this->data;
}

template <class T>
MyVector<T>::MyVector (const MyVector& other){
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; i++){
        this->data[i] = other.data[i];
    }
}

template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& other){
    if(this != &other){
        delete[] this->data;
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new T[this->capacity];

        for(int i = 0; i < this->size; i++){
            this->data[i] = other.data[i];
        }
    }
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T e){
    if(this->size >= this->capacity){
        this->grow();
    }
    this->shiftRight();
    this->data[0] = e;
    this->size++;

    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T e){
    if(this->size >= this->capacity){
        this->grow();
    }
    this->data[this->size] = e;
    this->size++;

    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }
    e = this->data[0];
    this->shiftLeft();
    this->size--;

    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e){
    if(isEmpty()){
        throw BADINDEX();
    }
    this->size--;
    e = this->data[this->size];

    return *this;
}

template <class T>
T  MyVector<T>::front(){
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->data[0];
}

template <class T>
T  MyVector<T>::back(){
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->data[this->size - 1];
}

template <class T>
T&  MyVector<T>::operator [](int ndx){
    if(ndx < 0 || ndx >= this->size){
        throw BADINDEX();
    }
    return this->data[ndx];
}

template <class T>
int MyVector<T>::getSize(){
    return this->size;
}

template <class T>
bool MyVector<T>::isEmpty(){
    return this->size == 0;
}

template <class T>
void MyVector<T>::erase(){
    delete[] this->data;
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
}

#endif //PROJ10_PROJ10_MYVECTOR_H
