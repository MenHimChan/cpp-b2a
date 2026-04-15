#include <iostream>

using namespace std;

class Person {
public:
    int m_age;
    mutable char m_sex;
    Person(int age, char sex) : m_age(age), m_sex(sex) {}

    // 类的常函数，承诺不修改类的属性
    // 底层原理是const 修饰了this指针，造成this指针指向的内容均不可修改
    void const_setAge(int age) const {
        // const成员函数不能修改成员变量
        // m_age = age; // 编译错误
        // 但是能读取成员变量
        cout << "Person setAge function called ! " << endl;
        cout << "m_age : " << m_age << endl;

        // 如果待修改的变量mutable修饰，则可以在const成员函数中修改：
        m_sex = 'm';
    }

    void setAge(int age) {
        this->m_age = age;
    }
};

int main() {
    Person p1(10, 'f');
    p1.const_setAge(15);            
    cout << "m.sex : " << p1.m_sex << endl;

    cout << "-------------------------" << endl;

    const Person p2(15, 'm');                   // 常量对象
    cout << "p2.m_age : " << p2.m_age << endl;
    // p2.m_age = 16;                           // 常量内部非mutable修饰属性都不可更改
    p2.m_sex = 'f';                             // 常量对象的mutable属性允许修改
    cout << "p2.m_sex : " << p2.m_sex << endl;

    // p2.setAge(100);                             // 报错 ： 常量对象必须只能调常量函数
    p2.const_setAge(10);                           // 可以调用常量函数
    cout << "p2.m_sex : " << p2.m_sex << endl;

    return 0;
}