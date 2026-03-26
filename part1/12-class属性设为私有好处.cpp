#include <iostream>

using namespace std;

// 类设为私有的好处：
// 1. 可人为控制读写权限，读设置get函数，写设置set函数
// 2. 可以认为验证有效性
class Person {
private:
    int m_age;
    string m_name = "张三";         // 直接初始化成员变量，C++11新特性

public:
    Person() = default;
    ~Person() = default;
    
    void setAge(int age) {
        // 验证年龄的有效性 
        if (age > 100 || age < 0)
        {
            cerr << "年龄输入无效！" << endl;
            return;
        }
        m_age = age;
    }

    int getAge() {
        return m_age;
    }
    
    // 名字不可以修改，所以没有set函数
    // void setName(string name) {
    //     m_name = name;
    // }

    string getName() {
        return m_name;
    }
};

int main() {
    Person p;
    p.setAge(18);
    cout << "年龄：" << p.getAge() << endl;
    cout << "名字：" << p.getName() << endl;
    return 0;
}