#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#ifdef DOUBLE_LINK_LIST
        double_link_list<int> list;
#endif

#ifdef LINK_LIST
        link_list<int> list;
#endif

long nnodes = 0;
long ins_nodes_success = 0;
long ins_nodes_fail = 0;
long find_nodes_success = 0;
long find_nodes_fail = 0;
long del_nodes_success = 0;
long del_nodes_fail = 0;

void test_add(int number) {
        bool ans = false;
        for (int i = 0; i < number; ++i) {
                int j = rand()%10000;
                ans = list.ins(j);
                if (ans) {
                        ++nnodes;
                        ++ins_nodes_success;
                } else {
                        ++ins_nodes_fail;
                }
        }

        return ;
}

void test_find(int number) {
        bool ans = false;
        for (int i = 0; i < number; ++i) {
                int j = rand()%10000;
                ans = list.find(j);
                if (ans) {
                        ++find_nodes_success;
                } else {
                        ++find_nodes_fail;
                }
        }

        return ;
}

void test_del(int number) {
        bool ans = false;
        for (int i = 0; i < number; ++i) {
                int j = rand()%10000;
                ans = list.del(j);
                if (ans) {
                        ++del_nodes_success;
                        --nnodes;
                } else {
                        ++del_nodes_fail;
                }
        }

        return ;
}


int main (int argc, char *argv[]) {
        if (argc != 4) {
                return 0;
        }

        std::string program_name = argv[0];
        int ins_number = atoi(argv[1]);
        int find_number = atoi(argv[2]);
        int del_number = atoi(argv[3]);
        //使用当前时间戳作为随机种子
        std::srand(std::time(nullptr));

        test_add(ins_number);
        test_find(find_number);
        test_del(del_number);

        std::cout << "nnodes : " << nnodes << std::endl;
        std::cout << "ins_number : " << ins_number << " success : " << ins_nodes_success << " fail : " << ins_nodes_fail << std::endl;
        std::cout << "find_number : " << find_number << " success : " << find_nodes_success << " fail : " << find_nodes_fail << std::endl;
        std::cout << "del_number : " << del_number << " success : " << del_nodes_success << " fail : " << del_nodes_fail << std::endl;

        return 0;
}