#include <iostream>

struct ReferenceStruct {
    int& ref;       // 引用成员
};

struct PointerStruct {
    int* const ptr; // 指针常量成员
};

// 因为引用本质就是一个指针常量，故
// 不可以被修改，不可以被指向其他对象
int main() {
    std::cout << "引用结构体大小: " << sizeof(ReferenceStruct) << " 字节" << std::endl;
    std::cout << "指针结构体大小: " << sizeof(PointerStruct) << " 字节" << std::endl;
    return 0;
}