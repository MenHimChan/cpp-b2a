#include <iostream>

using namespace std;

class Person {
public:
    int age;

    void func1() {
        cout << "Func1 called ! " << endl;
    }

    void func2() {
        cout << "Func2 called , age = " << this->age << endl;
    }

    static void func3() {
        cout << "Func3 called ! " << endl;
    }
};

int main() {
    
    Person* p1 = nullptr;

    // 空指针可以调用没有访问成员变量的成员函数， 因为没有用到this指针
    // 等价于func1(p1)， 这里的p1是nullptr， 但是func1函数没有访问成员变量，所以不会崩溃   
    p1->func1();        
    p1->func3();

    // 报错： 空指针调用成员函数时，访问了成员变量 age，导致程序崩溃
    p1->func2();   

    return 0;
}