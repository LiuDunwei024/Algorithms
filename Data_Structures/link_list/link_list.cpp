#include <iostream>
#include "../output_define.h"
#include "Node_define.h"

#define LINK_LIST

template<typename T>
class link_list {
public:
        link_list() {_head = NULL;}
        ~link_list() {
                Node<T> *curNode;
                while (_head) {
                        curNode = _head;
                        _head = _head->next;
                        delete curNode;
                        curNode = NULL;
                }
        }

        Node<T>* search(T value);
        bool find(T value);
        bool ins(T value);
        bool del(T value);
        void show();

private:
        Node<T> *_head;
};

template<typename T>
Node<T> * link_list<T>::search(T value) {
        if (NULL == _head) {
                return NULL;
        } 

        Node<T> *curNode = _head;
        while (curNode && curNode->value < value) {
                curNode = curNode->next;
        }
        return curNode;
}

template<typename T>
bool link_list<T>::find(T value) {
        Node<T> *tempNode = search(value);
        if (tempNode == NULL) {
#ifdef DEBUG
        FIND_FAIL();
#endif
                return false;
        }
        if (tempNode->value == value) {
#ifdef DEBUG
        FIND_SUCCESS();
#endif
                return true;
        } else {
#ifdef DEBUG
        FIND_FAIL();
#endif
                return false;                
        }
}

template<typename T>
bool link_list<T>::ins(T value) {
        //链表为空时
        if (_head == NULL) {
                _head = new Node<T>();
                _head->value = value;
                _head->next = NULL;
#ifdef DEBUG
        INSERT_SUCCESS();
#endif
                return true;
        }
        //链表不为空
        Node<T> *prevNode = NULL;
        Node<T> *curNode = _head;
        while (curNode && curNode->value < value) {
                prevNode = curNode;
                curNode = curNode->next;
        }
        //在末尾插入节点
        if (curNode == NULL) {
                curNode = new Node<T>();
                curNode->value = value;
                curNode->next = NULL;
                prevNode->next = curNode;
#ifdef DEBUG
        INSERT_SUCCESS();
#endif                
                return true;
        }

        if (curNode->value == value) {
#ifdef DEBUG
        INSERT_FAIL();
#endif                
                return false;
        } else {
                //在头部插入节点
                if (curNode == _head) {
                        prevNode = new Node<T>();
                        prevNode->value = value;
                        prevNode->next = curNode;
                        _head = prevNode;
#ifdef DEBUG
        INSERT_SUCCESS();
#endif
                        return true;
                } else {
                        Node<T> *newNode = new Node<T>();
                        newNode->value = value;
                        newNode->next = curNode;
                        prevNode->next = newNode;
#ifdef DEBUG
        INSERT_SUCCESS();
#endif                        
                        return true;
                }
        }

#ifdef DEBUG
        INSERT_FAIL();
#endif
        return false;
}

template<typename T>
bool link_list<T>::del(T value) {
        if (_head == NULL) {
#ifdef DEBUG
        DELETE_FAIL();
#endif
                return false;
        }

        Node<T> *prevNode = NULL;
        Node<T> *curNode = _head;
        while (curNode && curNode->value < value) {
                prevNode = curNode;
                curNode = curNode->next;
        }
        //未找到节点
        if (curNode == NULL) {
#ifdef DEBUG
        DELETE_FAIL();
#endif                
                return false;
        } else {
                if (curNode->value == value) {        
                        if (curNode == _head) { //删除头节点
                                _head = curNode->next;
                                delete curNode;
                                curNode = NULL;
#ifdef DEBUG
        DELETE_SUCCESS();
#endif                                
                                return true;
                        } else {
                                prevNode->next = curNode->next;
                                delete curNode;
                                curNode = NULL;
#ifdef DEBUG
        DELETE_SUCCESS();
#endif                                    
                                return true;
                        }
                }
        }

#ifdef DEBUG
        DELETE_FAIL();
#endif    
        return false;
}

template<typename T>
void link_list<T>::show() {
        Node<T> *curNode = _head;

        while (curNode != NULL) {
                std::cout << curNode->value << "->";
                curNode = curNode->next;
        }
        std::cout << "NULL" << std::endl;
        return ;
}

#include "microbench.h"