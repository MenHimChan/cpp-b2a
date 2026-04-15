#include <iostream>

using namespace std;

// 多个同类型的对象会共享同一份成员函数的内存实例
class Person {
public:
    char sex; // 1 byte
    char rich; // 1 byte
    int age;   // 4 byte
    
    // 成员函数、静态成员函数、静态成员变量均不占对象内存
    void func() {}
    static void func2() {}
    static int count; // 静态成员变量不占对象内存
};

int Person::count = 0;

// 空类的大小为1
// 类的大小不是成员变量大小之和，
// 而是非静态成员变量大小之和加上内存对齐的填充字节

void test() {
    cout << "sizeof(Person) : " << sizeof(Person) << endl;
}

int main() {
    test();
    return 0;
}
