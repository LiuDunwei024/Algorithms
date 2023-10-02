//定义输出格式
#include <iostream>

const void INSERT_SUCCESS() {
        std::cout << "Insert Success!" << std::endl;
}

template <typename T>
const void INSERT_SUCCESS(T val) {
        std::cout << "Insert " << val <<" Success!" << std::endl;
}

const void INSERT_FAIL() {
        std::cout << "Insert Fail!" << std::endl;
}

template <typename T>
const void INSERT_FAIL(T val) {
        std::cout << "Insert " << val <<" Fail!" << std::endl;
}

const void FIND_SUCCESS() {
        std::cout << "Find Success!" << std::endl;
}

template <typename T>
const void FIND_SUCCESS(T val) {
        std::cout << "Find " << val << " Success!" << std::endl;
}

const void FIND_FAIL() {
        std::cout << "Find Fail!" << std::endl;
}

template <typename T>
const void FIND_FAIL(T val) {
        std::cout << "Find " << val << " Fail!" << std::endl;
}

const void DELETE_SUCCESS() {
        std::cout << "Delete Success!" << std::endl;
}

template <typename T>
const void DELETE_SUCCESS(T val) {
        std::cout << "Delete " << val << " Success!" << std::endl;
}

const void DELETE_FAIL() {
        std::cout << "Delete Fail!" << std::endl;
}

template <typename T>
const void DELETE_FAIL(T val) {
        std::cout << "Delete " << val << " Fail!" << std::endl;
}