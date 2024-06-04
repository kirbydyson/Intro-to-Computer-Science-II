// File: proj10-Queue3.h
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 10
// Due Date: 11/04/2023

// Date Modified: 11/28/2023
//     -File created
// Date Modified: 12/02/2023
//     -File finished
// Implementation using MyList implementation

#ifndef PROJ10_PROJ10_QUEUE3_H
#define PROJ10_PROJ10_QUEUE3_H

#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
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
void Queue3<T>::enqueue(T e){
    this->pushBack(e);
}

template <class T>
void Queue3<T>::dequeue(T& e){
    this->popFront(e);
}

#endif //PROJ10_PROJ10_QUEUE3_H
