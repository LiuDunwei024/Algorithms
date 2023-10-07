#ifndef __NODE_DEFINE_H__
#define __NODE_DEFINE_H__

template <typename T>
struct Node {
public:
        T value;
        Node<T> *left;
        Node<T> *right;
        Node<T> *parent;
};

#endif