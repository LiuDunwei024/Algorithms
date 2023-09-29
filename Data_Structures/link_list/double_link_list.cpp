#include <iostream>
#include "../output_define.h"
#include "Node_define.h"


#define DOUBLE_LINK_LIST

template<typename T>
class double_link_list
{
public:
        double_link_list(){}
        ~double_link_list(){
                Node<T> *curNode;
                while (head) {
                        curNode = head;
                        head = head->next;
                        delete curNode;
                        curNode = NULL;
                }
        }
        bool find(T val);
        bool ins(T val);
        bool del(T val);
        void show();


private:
        Node<T> *search(T val);
        void ins_head(Node<T> *ins_node);
        void ins_tail(Node<T> *ins_node);
        void ins_mid(Node<T> *ins_node, Node<T> *cur_node);
        void del_head(Node<T> *del_node);
        void del_tail(Node<T> *del_node);
        void del_mid(Node<T> *del_node);
        Node<T> *head;
        Node<T> *tail;
};

template<typename T>
void double_link_list<T>::ins_head(Node<T> *ins_node) {
        if (NULL == head) {
                head = ins_node;
                tail = ins_node;
        } else {
                ins_node->next = head;
                head->prev = ins_node;
                head = ins_node;
        }
}

template<typename T>
void double_link_list<T>::ins_tail(Node<T> *ins_node) {
        ins_node->prev = tail;
        tail->next = ins_node;
        tail = ins_node;
}

template<typename T>
void double_link_list<T>::ins_mid(Node<T> *ins_node, Node<T> *cur_node) {
        ins_node->next = cur_node;
        ins_node->prev = cur_node->prev;
        ins_node->prev->next = ins_node;
        ins_node->next->prev = ins_node;
}

template<typename T>
void double_link_list<T>::del_head(Node<T> *del_node) {
        head = del_node->next;
        head->prev = NULL;
        del_node->next = NULL;
        delete del_node;
        del_node = NULL;
}

template<typename T>
void double_link_list<T>::del_tail(Node<T> *del_node) {
        tail = tail->prev;
        tail->next = NULL;
        del_node->prev = NULL;
        delete del_node;
        del_node = NULL;
}

template<typename T> 
void double_link_list<T>::del_mid(Node<T> *del_node) {
        del_node->prev->next = del_node->next;
        del_node->next->prev = del_node->prev;
        del_node->prev = NULL;
        del_node->next = NULL;
        delete del_node;
        del_node = NULL;
}

template<typename T>
Node<T> *double_link_list<T>::search(T val) {
        if (NULL == head) {
                return head;
        }

        Node<T> *curNode = NULL;
        curNode = head;
        while (curNode && curNode->value < val) {
                curNode = curNode->next;
        }
        
        return curNode;
}

template<typename T>
bool double_link_list<T>::find(T val) {
        Node<T> *curNode = search(val);

        bool ans = false;
        if (NULL == curNode) {
                ans = false;
        } else {
                if (val == curNode->value) {
                        ans = true;
                }
        }

# ifdef DEBUG
        if (ans) {
                FIND_SUCCESS();
        } else {
                FIND_FAIL();
        }
# endif

        return ans;
}

template<typename T>
bool double_link_list<T>::ins(T val) {
        bool ans = false;
        if (NULL == head) {
                Node<T> *ins_node = new Node<T>();
                ins_node->value = val;
                ins_head(ins_node);
                ans = true;
        } else {
                Node<T> *cur_node = search(val);
                if (NULL == cur_node) {
                        //在尾部插入节点
                        Node<T> *ins_node = new Node<T>();
                        ins_node->value = val;
                        ins_tail(ins_node);
                        ans = true;
                } else {
                        if (val == cur_node->value) {
                                //节点存在，插入失败
                                ans = false;
                        } else {
                                if (head == cur_node) {
                                        //在头节点前插入
                                        Node<T> *ins_node = new Node<T>();
                                        ins_node->value = val;
                                        ins_head(ins_node);
                                        ans = true;
                                } else {
                                        //在中间插入节点
                                        Node<T> *ins_node = new Node<T>();
                                        ins_node->value = val;
                                        ins_mid(ins_node, cur_node);
                                        ans = true;
                                }
                        }
                }
        }

# ifdef DEBUG
        if (ans) {
                INSERT_SUCCESS();
        } else {
                INSERT_FAIL();
        }
# endif
        return ans;
}

template<typename T>
bool double_link_list<T>::del(T val) {
        bool ans = false;

        if (NULL == head) {
                ans = false;
        } else {
                Node<T> *cur_node = search(val);
                if (NULL == cur_node || val != cur_node->value) {
                        ans = false;
                } else {
                        if (head == cur_node) {
                                del_head(cur_node);
                                ans = true;
                        } else if (tail == cur_node) {
                                del_tail(cur_node);
                                ans = true;
                        } else {
                                del_mid(cur_node);
                                ans = true;
                        }
                }
        }

# ifdef DEBUG
        if (ans) {
                DELETE_SUCCESS();
        } else {
                DELETE_FAIL();
        }
# endif
        return ans;
}

template<typename T>
void double_link_list<T>::show(){
        Node<T> *cur_node = head;
        while (cur_node) {
                std::cout << cur_node->value;
                if (tail != cur_node) {
                        std::cout << "<=>";
                } else {
                        std::cout << std::endl;
                }
                cur_node = cur_node->next;
        }
}

#include "microbench.h"