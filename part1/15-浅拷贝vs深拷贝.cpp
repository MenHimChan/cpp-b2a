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

private:
    int* m_age_ptr;
};

int main() {
    Person p1;
    Person p2(p1);      // 浅拷贝，p1和p2的m_age_ptr指向同一块内存, 析构时候造成重复释放内存
    return 0;
}