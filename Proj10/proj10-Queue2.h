// File: proj10-Queue2.h
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 10
// Due Date: 12/04/2023

// Date Modified: 11/28/2023
//     -File created
// Date Modified: 12/02/2023
//     -File finished
// Still uses the MyVector, but implemented using “circular” array

#ifndef PROJ10_PROJ10_QUEUE2_H
#define PROJ10_PROJ10_QUEUE2_H

#include "proj10-MyVector.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
    int front, rear;

public:
    /*
     *Queue2
     *
     *This function constructs a new Queue2 object
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: none
     *    reference parameters: none
     *    stream: none
    */
    Queue2();
    /*
     *enqueue
     *
     *This function adds element to the back of the queue
     *
     *Parameters:
     *    e: element added to queue
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void enqueue( T );
    /*
     *dequeue
     *
     *This function removes element at the front of the queue
     *
     *Parameters:
     *    e: reference to element
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void dequeue( T& ); // throws BADINDEX
};

template <class T>
Queue2<T>::Queue2(){
    this->front = -1;
    this->rear = -1;
}

template <class T>
void Queue2<T>::enqueue(T e){
    if(this->size >= this->capacity){
        int ndx = this->front;
        this->capacity *= 2;
        T *temp = new T[this->capacity];
        for (int i = 0; i < this->size; i++){
            temp[i] = this->data[ndx];
            ndx++;
            if (ndx >= this->capacity / 2){
                ndx = 0;
            }
        }
        this->front = 0;
        this->rear = this->size - 1;

        delete [] this->data;
        this->data = temp;
    }

    this->rear++;
    if (this->rear >= this->capacity){
        this->rear = 0;
    }

    this->data[this->rear] = e;
    this->size++;
}

template <class T>
void Queue2<T>::dequeue(T& e){
    if(this->size <= 0){
        throw BADINDEX();
    }
    e = this->data[this->front];
    this->front++;
    if(this->front > this->rear){
        this->front = -1;
        this->rear = -1;
    }
}

#endif //PROJ10_PROJ10_QUEUE2_H
