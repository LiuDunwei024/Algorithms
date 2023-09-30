#include <iostream>
#include <vector>
#include "../output_define.h"
#include "Node_define.h"

#define LINK_LIST_TAG

template<typename T>
class link_list_tag {
public:
        link_list_tag() {
                head = new Node<T>();
                tail = new Node<T>();
                head->value = 0;
                tail->value = 0;
                head->next = tail;
        }
        ~link_list_tag() {
                Node<T> *curNode = NULL;
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
        void search(T val, snapshot<T> &ss);
        void ins(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode);
        void del(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode);
        Node<T> *head;
        Node<T> *tail;
};

template<typename T>
void link_list_tag<T>::search(T val, snapshot<T> &ss) {
        Node<T> *prevnode = head;
        Node<T> *curnode = head->next;

        while (curnode != tail && curnode->value < val) {
                prevnode = curnode;
                curnode = curnode->next;
        }

        ss.prev = prevnode;
        //curnode结果两种情况：1）value大于等于val的第一个节点 2）tail即所有节点的值小于val
        ss.cur = curnode;

        return ;
}

template<typename T>
void link_list_tag<T>::ins(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode) {
        prevnode->next = curnode;
        curnode->next = nextnode;
}

template<typename T>
void link_list_tag<T>::del(Node<T> *prevnode, Node<T> *curnode, Node<T> *nextnode) {
        prevnode->next = nextnode;
        delete curnode;
        curnode = NULL;
}

template<typename T>
bool link_list_tag<T>::find(T val) {
        snapshot<T> ss;
        search(val, ss);
        if (tail == ss.cur) {
                //所有节点小于val
#ifdef DEBUG
        FIND_FAIL();
#endif
                return false;
        } else {
                if (val == ss.cur->value) {
                        //查找到节点
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

#ifdef DEBUG
        FIND_FAIL();
#endif
        return false;
}

template<typename T>
bool link_list_tag<T>::ins(T val) {
        snapshot<T> ss;
        search(val, ss);

        if (tail == ss.cur) {
                //所有节点的值小于val
                Node<T> *ins_node = new Node<T>();
                ins_node->value = val;
                ins(ss.prev, ins_node, ss.cur);
#ifdef DEBUG
        INSERT_SUCCESS();
#endif
                return true;
        } else {
                if (val == ss.cur->value) {
                        //存在值为val的节点
#ifdef DEBUG
        INSERT_FAIL();
#endif
                        return false;
                } else {
                        //插入节点
                        Node<T> *ins_node = new Node<T>();
                        ins_node->value = val;
                        ins(ss.prev, ins_node, ss.cur);
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
bool link_list_tag<T>::del(T val) {
        snapshot<T> ss;
        search(val, ss);

        if (tail == ss.cur) {
                //不存在值为val的节点
#ifdef DEBUG
        DELETE_FAIL();
#endif
        } else {
                if (val == ss.cur->value) {
                        //删除节点
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
void link_list_tag<T>::show() {
        Node<T> *curnode = head;

        while (curnode) {
                if (head == curnode) {
                        std::cout << "head -> ";
                } else if (tail == curnode) {
                        std::cout << "tail" << std::endl;
                } else {
                        std::cout << curnode->value << " -> ";
                }
                curnode = curnode->next;
        }
}

#ifdef test
int main() {
        link_list_tag<char> list;
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