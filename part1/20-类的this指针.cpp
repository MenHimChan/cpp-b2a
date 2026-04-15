#include <iostream>

using namespace std;

// this指针指向类的对象本身
// this 只在【成员函数被调用时】才存在。
// this指针是一个隐含的参数，所有非静态成员函数都有一个this指针，
// 指向调用该成员函数的对象

class Person {
public:
    int age;
    char sex;

    // 两种必须要用this指针的情况
    // 1 必须要用this指针来区分成员变量和参数同名的情况
    Person& setSex(char sex) {
        // sex = sex;       // 造成歧义
        this->sex = sex;
        return *this;
    }

    Person& setAge(int age) {
        this->age = age;
        return *this;
    }

    // 2 this指针可以在成员函数中返回对象本身，支持链式调用
    void AddAge(int increment) {
        this->age += increment;
    }

    Person& AddAgeLink(int increment) {
        this->age += increment;
        // 返回当前对象的引用，支持链式调用
        return *this;
    }

    Person* AddAgeChain(int increment) {
        this->age += increment;
        // 返回当前对象的指针，支持链式调用
        return this;
    }


};

int main() {
    Person p1;
    p1.setAge(20)
      .setSex('M');             // 链式调用设置年龄和性别

    p1.AddAge(5);
    cout << "p1 age: " << p1.age << endl; // 输出 25

    // 看起来像：对象.动作().动作();
    p1.AddAgeLink(5).AddAgeLink(5); // 链式调用
    cout << "p1 age after chain: " << p1.age << endl; //

    // 看起来像：地址->动作()->动作();
    p1.AddAgeChain(5)->AddAgeChain(5); // 链式调用
    cout << "p1 age after chain with pointer: " << p1.age << endl;

    return 0;
} 