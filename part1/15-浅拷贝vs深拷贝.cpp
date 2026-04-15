#include <iostream>

using namespace std;

class Person {
public:
    Person(): m_age_ptr(new int(50)) {
        cout << "Person的构造函数被调用了" << endl;
    }

    ~Person() {
        delete m_age_ptr;
        m_age_ptr = nullptr;
        cout << "Person的析构函数被调用了" << endl;
    }

    // 解决方法： 自己写一块拷贝构造函数，进行深拷贝
    // 若注释掉，则代码执行报错
    Person(const Person& other) {
        // 编译器默认实现的逻辑：
        // m_age_ptr = other.m_age_ptr;          // 浅拷贝，两个对象的m_age_ptr指向同一块内存
        m_age_ptr = new int{*(other.m_age_ptr)}; // 深拷贝，分配新的内存，并将值复制过来
        cout << "Person的拷贝构造函数被调用了" << endl;
    }

private:
    int* m_age_ptr;
};

int main() {
    Person p1;
    Person p2(p1);      // 深拷贝，p1和p2的m_age_ptr指向不同的内存
    return 0;
}