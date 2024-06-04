// File: proj10-Queue1.h
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 10
// Due Date: 12/04/2023

// Date Modified: 11/28/2023
//     -File created
// Date Modified: 12/02/2023
//     -File finished
// Naive implementation of queue using MyVector implementation

#ifndef PROJ10_PROJ10_QUEUE1_H
#define PROJ10_PROJ10_QUEUE1_H

#include "proj10-MyVector.h"

template <class T>
class Queue1 : public MyVector<T> {
public:
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
void Queue1<T>::enqueue(T e){
    this->pushBack(e);
}

template <class T>
void Queue1<T>::dequeue(T& e){
    this->popFront(e);
}

#endif //PROJ10_PROJ10_QUEUE1_H
