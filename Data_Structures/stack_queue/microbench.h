#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <assert.h>

#ifdef STACK
        Stack<int> ss;
#endif

#ifdef QUEUE
        Queue<int> que;
#endif

#ifdef STACK
void test_stack(int num) {
        //使用当前时间戳作为随机种子
        std::srand(std::time(nullptr));

        int num1 = num;
        int num2 = num;
        int num3 = num;

        ss.top();
        while ((num1 + num2 + num3) != 0) {
                int i = rand()%num;
                int j = rand()%2;
                switch (j) {
                        case 0:
                                if (0 != num1) {
                                        ss.push(i);
                                        --num1;
                                        assert(ss.size() != 0);
                                        if (!ss.empty()) {
                                                std::cout << "top = " << ss.top() << std::endl;
                                                --num3;
#ifdef DEBUG
        std::cout << std::endl;
#endif                                                  
                                        }
                                }
                                break;
                        case 1:
                                if (0 != num2) {
#ifdef DEBUG
        std::cout << "ss size = " << ss.size() << std::endl;
#endif                                        
                                        ss.pop();
#ifdef DEBUG
        std::cout << "ss size = " << ss.size() << std::endl << std::endl;
#endif  
                                        --num2;
                                }
                                break;
                }
        }
}
#endif

#ifdef QUEUE
void test_que(int num) {
        //使用当前时间戳作为随机种子
        std::srand(std::time(nullptr));

        int num1 = num;
        int num2 = num;
        int num3 = num;
        que.front();
        que.back();
        while ((num1 + num2 + num3) != 0) {
                int i = rand()%num;
                int j = rand()%2;
                switch (j) {
                        case 0:
                                if (0 != num1) {
                                        que.push(i);
                                        --num1;
                                        assert(0 != que.size());
                                        if (!que.empty()) {
                                                std::cout << "que size = " << que.size() << " front = " << que.front() << " back = " << que.back() << std::endl;
                                                --num3;
#ifdef DEBUG
        std::cout << std::endl;
#endif                                                  
                                        }
                                }
                                break;
                        case 1:
                                if (0 != num2) {
#ifdef DEBUG
        std::cout << "que size = " << que.size() << std::endl;
#endif                                        
                                        que.pop();
#ifdef DEBUG
        std::cout << "que size = " << que.size() << std::endl << std::endl;
#endif                                        
                                        --num2;
                                }
                                break;
                }
        }
}
#endif

int main(int argc, char *argv[]) {
        if (argc != 2) {
                std::cout << "Error!" << std::endl;
                return 0;
        }

        int num = atoi(argv[1]);

#ifdef STACK        
        test_stack(num);
#endif
#ifdef QUEUE
        test_que(num);
#endif

        return 0;
}