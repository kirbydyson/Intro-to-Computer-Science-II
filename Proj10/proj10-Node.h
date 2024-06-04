//
// Created by kdyso on 11/28/2023.
//

#ifndef PROJ10_PROJ10_NODE_H
#define PROJ10_PROJ10_NODE_H

template <class T>
class Node {
public:
    T data;
    Node <T>*next;

    Node( T d ) {
        data = d;
        next = nullptr;
    }

    ~Node( ) {
        delete next;
    }
};

#endif //PROJ10_PROJ10_NODE_H
