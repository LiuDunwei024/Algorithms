#include <vector>
#include <assert.h>
#include <iostream>

#define QUEUE

template <typename T>
class Queue {
public:
        Queue() {
                _total_node = 0;
        }
        ~Queue(){}
        void push(T val);
        void pop();
        T back();
        T front();
        bool empty();
        long size();

private:
        std::vector<T> _queue;
        long _total_node;
};

template <typename T>
void Queue<T>::push(T val) {
        _queue.push_back(val);
        ++_total_node;
        return ;
}

template <typename T>
void Queue<T>::pop() {
        if (0 == _queue.size()) {
#ifdef DEBUG
        std::cout << "The size of _queue is zero, pop fail!" << std::endl;
#endif
                return ;
        }
#ifdef DEBUG
        assert(0 != _queue.size() && 0 != _total_node && _queue.size() == _total_node);
#endif        
        _queue.erase(_queue.begin());
        --_total_node;
#ifdef DEBUG
        std::cout << "pop success!" << std::endl;
#endif        
        return ;
}

template <typename T>
T Queue<T>::back() {
        if (0 == _queue.size()) {
#ifdef DEBUG
        std::cout << "The size of _queue is zero, back fail!" << std::endl;
#endif
                return -1;                
        }
#ifdef DEBUG
        assert(0 != _queue.size() && 0 != _total_node && _queue.size() == _total_node);
#endif        
        return _queue[_total_node-1];
}

template <typename T>
T Queue<T>::front() {
        if (0 == _queue.size()) {
#ifdef DEBUG
        std::cout << "The size of _queue is zero, front fail!" << std::endl;
#endif
                return -1;                
        }
#ifdef DEBUG
        assert(0 != _queue.size() && 0 != _total_node && _queue.size() == _total_node);
#endif        
        return _queue[0];
}

template <typename T>
bool Queue<T>::empty() {
#ifdef DEBUG        
        assert(_queue.size() == _total_node);
#endif        
        return 0 == _total_node;
}

template <typename T>
long Queue<T>::size() {
#ifdef DEBUG        
        assert(_queue.size() == _total_node);
#endif        
        return _total_node;
}

#include "microbench.h"