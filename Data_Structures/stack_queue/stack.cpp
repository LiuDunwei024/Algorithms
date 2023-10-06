#include <vector>
#include <assert.h>

#define Stack_H

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
                assert(_total_node == 0);
                return ;
        }
        assert(_stack.size() != 0);
        _stack.pop_back();
        --_total_node;
        return ;
}

template<typename T>
T Stack<T>::top() {
        if (0 == _total_node) {
                return -1;
        }
        T ans = _stack[_total_node - 1];
        return ans;
}

template <typename T>
bool Stack<T>::empty() {
        return 0 == _total_node;
}

template <typename T>
long Stack<T>::size() {
        return _total_node;
}

#include "microbench.h"