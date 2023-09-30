#include <iostream>
#include "../output_define.h"
#include "Node_define.h"

#define DOUBLE_LINK_LIST_TAG

template<typename T>
class double_link_list_tag {
public:
        double_link_list_tag() {
                head = new Node<T>();
                tail = new Node<T>();
                head->value = 0;
                tail->value = 0;
                head->next = tail;
                tail->prev = head;
        }
        ~double_link_list_tag() {
                Node<T> *curnode = NULL;
                while (head) {
                        curnode = head;
                        head = head->next;
                        curnode->prev = NULL;
                        curnode->next = NULL;
                        delete curnode;
                        curnode = NULL;
                }
        }
        bool find(T val);
        bool ins(T val);
        bool del(T val);
        void show();
private:
        void search(T val, snapshot<T> &ss);
        void ins(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode);
        void del(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode);
        Node<T> *head;
        Node<T> *tail;

};

template<typename T>
void double_link_list_tag<T>::search(T val, snapshot<T> &ss) {
        Node<T> *curnode = head->next;
        while (tail != curnode && curnode->value < val) {
                curnode = curnode->next;
        }

        ss.prev = curnode->prev;
        //curnode结果两种情况：1）value大于等于val的第一个节点 2）tail即所有节点的值小于val
        ss.cur = curnode;

        return ;
}

template<typename T>
void double_link_list_tag<T>::ins(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode) {
        curnode->prev = prevnode;
        prevnode->next = curnode;
        curnode->next = nextnode;
        nextnode->prev = curnode;
}

template<typename T>
void double_link_list_tag<T>::del(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode) {
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        curnode->next = NULL;
        curnode->prev = NULL;
        delete curnode;
        curnode = NULL;
}

template<typename T>
bool double_link_list_tag<T>::find(T val) {
        snapshot<T> ss;
        search(val, ss);

        if (tail == ss.cur) {
                //不存在值为val的节点
#ifdef DEBUG
        FIND_FAIL();
#endif
                return false;
        } else {
                if (val == ss.cur->value) {
                        //存在值为val的节点
#ifdef DEBUG
        FIND_SUCCESS();
#endif
                        return true;
                } else {
                        //不存在值为val的节点
#ifdef DEBUG
        FIND_FAIL();
#endif
                        return false;
                }
        }

#ifdef DEBUG
        FIND_FAIL();
#endif
        return false;
}

template<typename T>
bool double_link_list_tag<T>::ins(T val) {
        snapshot<T> ss;
        search(val, ss);

        if (tail == ss.cur) {
                //不存在值为val的节点，且所有节点值小于val
                //在尾部插入节点val
                Node<T> *curnode = new Node<T>();
                curnode->value = val;
                ins(ss.prev, curnode, ss.cur);
#ifdef DEBUG
        INSERT_SUCCESS();
#endif
                return true;
        } else {
                if (val == ss.cur->value) {
                        //存在值为val的节点，插入失败
#ifdef DEBUG
        INSERT_FAIL();
#endif
                        return false;
                } else {
                        //插入节点
                        Node<T> *curnode = new Node<T>();
                        curnode->value = val;
                        ins(ss.prev, curnode, ss.cur);
#ifdef DEBUG
        INSERT_SUCCESS();
#endif
                        return true;
                }
        }
}

template<typename T>
bool double_link_list_tag<T>::del(T val) {
        snapshot<T> ss;
        search(val, ss);

        if (tail == ss.cur) {
                //不存在值为val的节点
#ifdef DEBUG
        DELETE_FAIL();
#endif
                return false;
        } else {
                if (val == ss.cur->value) {
                        //存在值为val的节点
                        del(ss.prev, ss.cur, ss.cur->next);
#ifdef DEBUG
        DELETE_SUCCESS();
#endif
                        return true;
                } else {
                        //不存在值为val的节点
#ifdef DEBUG
        DELETE_FAIL();
#endif
                        return false;
                }
        }

#ifdef DEBUG
        DELETE_FAIL();
#endif
        return false;        
}

template<typename T>
void double_link_list_tag<T>::show() {
        Node<T> *curnode = head;

        while (curnode) {
                if (head == curnode) {
                        std::cout << "head <=> ";
                } else if (tail == curnode) {
                        std::cout << "tail" << std::endl;
                } else {
                        std::cout << curnode->value << " <=> ";
                }
                curnode = curnode->next;
        }
}

#ifdef TEST
int main() {
        double_link_list_tag<char> list;
        list.ins('a');
        list.show();
        list.ins('e');
        list.show();
        list.ins('b');
        list.ins('c');
        list.ins('d');
        list.show();
        list.ins('c');
        list.show();

        std::cout << "============================" << std::endl;

        list.find('a');
        list.find('f');

        std::cout << "============================" << std::endl;
        list.del('e');
        list.show();
        list.del('a');
        list.show();
        list.del('c');
        list.show();
        list.del('a');
        list.show();

        return 0;
}
#else
#include "microbench.h"
#endif