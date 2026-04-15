#include <iostream>

using namespace std;

class Person {
public: 
    Person() = default;
    ~Person() = default;
    
    // class的静态属性
    // 1 所有对象共享同一份数据
    // 2 编译阶段分配内存，程序结束时释放内存
    // 3 类内声明，在类外初始化
    static int person_num;  // 静态成员变量
    int age;                // 非静态成员变量

    // class的静态成员函数
    // 1 只能访问静态成员变量，不能访问非静态成员变量
    // 2 可通过对象访问，也可通过类名访问
    static void func() {
        cout << person_num << endl; // 可以访问静态成员变量
        // cout << age << endl;        // 错误，不能访问非静态成员变量
        cout << "这是一个静态成员函数" << endl;
    }

};

int Person::person_num = 0; // 类外初始化

int main() {

    Person p1;
    // 通过对象访问静态成员变量 通过类名访问静态成员变量
    cout << p1.person_num << endl;      // 0
    cout << Person::person_num << endl; // 0

    cout << "-----------------------------" << endl;

    // 通过对象访问静态成员函数 通过类名访问静态成员函数
    p1.func();                          // 0 这是一个静态成员函数
    Person::func();                     // 0 这是一个静态成员函数

    return 0;
}