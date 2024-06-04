//
// Created by kdyso on 11/9/2023.
//

#ifndef PROJ9_PROJ9_NODE_H
#define PROJ9_PROJ9_NODE_H

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T e) {
        data = e;
        next = nullptr;
    }
};

#endif //PROJ9_PROJ9_NODE_H
