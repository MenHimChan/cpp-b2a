#include <iostream>

using namespace std;

// 父类指针可以指向子类对象
// 不做任何其他处理情况下，析构时候不会调用子类的析构函数。
class Base {
public:
    Base() {
        cout << "Calling Base() ! " << endl;
    }

    // 加virtual关键字： 让父类指针释放的时候可以调用到子类的析构函数
    virtual ~Base() {
        cout << "Calling ~Base() ! " << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Calling Derived() ! " << endl;
    }
    ~Derived() {
        cout << "Calling ~Derived() ! " << endl;
    }
};

int main() {
    Base* baseptr = new Derived;
    delete baseptr;
    return 0;
}