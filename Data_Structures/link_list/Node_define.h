#ifndef _NODE_DEFINE_H_
#define _NODE_DEFINE_H_

template<typename T>
struct Node{
        T value;
        Node<T> *prev;
        Node<T> *next;
};

template<typename T>
struct snapshot {
        Node<T> *prev;
        Node<T> *cur;
};

#endif