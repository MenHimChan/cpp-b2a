#include <iostream>

using namespace std;

class Person {
private:
    int age;
    string name;
    
public:
    Person() {
        cout << "Person() 构造函数被调用了" << endl;
    }

    Person(int age) {
        this->age = age;
        cout << "Person(int age) 构造函数被调用了" << endl;
    }

    Person(const Person& p) {
        age = p.age;
        name = p.name;
        cout << "Person(const Person& p) 拷贝构造函数被调用了" << endl;
    }

    ~Person() {
        cout << "析构函数被调用了" << endl;
    }

    int getAge() {
        return age;
    }
};

void test01(Person p) {
    cout << "test01 函数被调用了" << endl;
}

Person test02() {
    Person p(30);
    return p;
}

int main() {
    Person p1(20);
    
    // 拷贝构造函数什么时候会被调用？
    // 1. 拷贝构造对象
    // Person p2(p1);

    // // 2. 值传递的方式给函数参数传值
    // test01(p1);

    // 3. 以值的方式返回局部对象
    // 因为编译器做了优化，直接在p3的内存空间上构造对象, 无法调用拷贝构造函数
    Person p3(10);
    p3 = test02(); // 这里会调用拷贝构造函数吗？不
    cout << p3.getAge() << endl; // 访问成员变量，验证对象是否正确构造

    return 0;
}