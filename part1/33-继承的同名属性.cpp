#include <iostream>

using namespace std;

class father {
public:
    int m_num = 100;
    int m_num1;
    int m_num2;

    void func() {
        cout << "father's func ! " << endl; 
    }
};

class son : public father {
public:
    int m_num = 200;
    void func() {
        cout << "son's func ! " << endl; 
    }
};


// 若出现子类和父类同名的属性或者方法：
// 只要想访问父类中的同名方法或者属性，就必须加上作用域。
void test01() {
    son s;
    cout << "m_num : " << s.m_num << endl;

    // 子类对象要通过作用域才能访问到父类的成员属性
    cout << "m_num : " << s.father::m_num << endl;
}

void test02() {
    son s;
    s.func();
    s.father::func();
}

int main() {
    // test01();
    test02();
    return 0;
}