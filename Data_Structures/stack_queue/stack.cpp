#include <vector>
#include <assert.h>
#include <iostream>

#define STACK

template <typename T>
class Stack{
public:
        Stack(){
                _total_node = 0;
        }
        ~Stack(){}
        void push(T val);
        void pop();
        T top();
        bool empty();
        long size();

private:
        std::vector<T> _stack;
        long _total_node;
};

template<typename T>
void Stack<T>::push(T val) {
        _stack.push_back(val);
        ++_total_node;
        return ;
}

template<typename T>
void Stack<T>::pop() {
        if (0 == _stack.size()) {
#ifdef DEBUG
        std::cout << "The size of _stack is zero, pop fail!" << std::endl;
#endif
                return ;
        }
#ifdef DEBUG
        assert(0 != _stack.size() && 0 != _total_node && _stack.size() == _total_node);
#endif  
        _stack.pop_back();
        --_total_node;
#ifdef DEBUG
        std::cout << "pop success!" << std::endl;
#endif          
        return ;
}

template<typename T>
T Stack<T>::top() {
        if (0 == _stack.size()) {
#ifdef DEBUG
        std::cout << "The size of _stack is zero, top fail!" << std::endl;
#endif
                return -1;                
        }
#ifdef DEBUG
        assert(0 != _stack.size() && 0 != _total_node && _stack.size() == _total_node);
#endif        
        return _stack[_total_node-1];
}

template <typename T>
bool Stack<T>::empty() {
#ifdef DEBUG        
        assert(_stack.size() == _total_node);
#endif           
        return 0 == _total_node;
}

template <typename T>
long Stack<T>::size() {
#ifdef DEBUG        
        assert(_stack.size() == _total_node);
#endif          
        return _total_node;
}

#include "microbench.h"