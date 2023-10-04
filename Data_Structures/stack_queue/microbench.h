#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <assert.h>

#ifdef Stack_H
        Stack<int> ss;
#endif

void test(int num) {
        //使用当前时间戳作为随机种子
        std::srand(std::time(nullptr));

        int num1 = num;
        int num2 = num;
        int num3 = num;

        while ((num1 + num2 + num3) != 0) {
                int i = rand()%num;
                int j = rand()%3;
                switch (j) {
                        case 0:
                                if (0 != num1) {
                                        ss.push(i);
                                        --num1;
                                }
                                break;
                        case 1:
                                if (0 != num2) {
                                        ss.pop();
                                        --num2;
                                }
                                break;
                        case 2:
                                if (0 != num3) {
                                        if (!ss.empty()) {
                                                assert(ss.size() != 0);
                                                std::cout << "top = " << ss.top() << std::endl;
                                                --num3;
                                        }
                                }
                                break;
                }
        }
}

int main(int argc, char *argv[]) {
        if (argc != 2) {
                std::cout << "Error!" << std::endl;
                return 0;
        }

        int num = atoi(argv[1]);
        test(num);

        return 0;
}