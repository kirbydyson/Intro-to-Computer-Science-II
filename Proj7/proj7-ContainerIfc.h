//
// Created by kdyso on 10/24/2023.
//

#ifndef PROJ7_PROJ7_CONTAINERIFC_H
#define PROJ7_PROJ7_CONTAINERIFC_H

class BADINDEX {};

template <class T>
class ContainerIfc {
public:
    virtual ContainerIfc<T>& pushFront(T)  =0;
    virtual ContainerIfc<T>& pushBack(T)   =0;
    virtual ContainerIfc<T>& popFront(T&)  =0; // throws BADINDEX
    virtual ContainerIfc<T>& popBack(T&)   =0; // throws BADINDEX
    virtual int getSize()         =0;
    virtual bool isEmpty()        =0;
    virtual T  front()            =0; // throws BADINDEX
    virtual T  back()             =0; // throws BADINDEX
    virtual T&  operator [](int)  =0; // throws BADINDEX
    virtual void erase()          =0;
};

#endif //PROJ7_PROJ7_CONTAINERIFC_H
