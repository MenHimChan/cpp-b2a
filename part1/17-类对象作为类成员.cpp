#include <iostream>

using namespace std;

// 类A作为类B的成员变量
// 创建B时候先创建A对象
// 析构顺序和构造顺序相反

class A {
public:
    A() {
        cout << "A constructor" << endl;
    }
    ~A() {
        cout << "A destructor" << endl;
    }
};

class B {
public:
    A a; // 这里会调用A的构造函数和析构函数

    B() {
        cout << "B constructor" << endl;
    }

    ~B() {
        cout << "B destructor" << endl;
    }
};

int main() {
    B b; // 创建B对象，自动调用A的构造函数和析构函数
    return 0;
}