#include <iostream>
#include <string>

using namespace std;    

class Person {
private:
    int age;
    string name;
    
public:
    // 1. 构造函数允许重载
    Person(): age(0), name("Tom") {
        cout << "Person() is called!" << endl;
    }

    Person(int a, string n) : age(a), name(n) {
        cout << "Person(int, string) is called!" << endl;
    }

    Person(int a) : age(a), name("Tom") {
        cout << "Person(int) is called!" << endl;
    }

    // 2. 构造方法可以分为： 普通构造 && 拷贝构造
    Person(const Person& p) : age(p.age), name(p.name) {
        cout << "Person(const Person&) is called!" << endl;
    }

    // 3. 析构函数不允许重载，且只能有一个析构函数
    ~Person() {
        cout << "~Person() is called!" << endl;
    }
};

int main() {

    // 类的构造方法的调用方式：
    // 1. 括号法 classname object_name(args);
    Person p1;                // 调用无参构造函数
    Person p2(18, "Jack");   // 调用有参构造函数
    Person p3(20);           // 调用有参构造函数
    Person p4(p2);           // 调用拷贝构造函数

    // 2. 显式构造法： classname object_name = classname(args);
    // Person(30, "Rose") 匿名对象，执行后立即销毁
    // 不能用拷贝构造函数构造匿名对象，因为匿名对象没有名字，无法作为参数传递给拷贝构造函数
    Person p5 = Person(30, "Rose");  // 调用有参构造函数，等价于 Person p5(30, "Rose");
    Person p6 = Person(p1);           // 调用有参构造函数，等价于 Person p6(40);

    // 3. 隐式构造法： classname object_name = args;
    // 
    Person p7 = 40;           // 调用有参构造函数，等价于 Person p7(40);
    Person p8 = p1;           // 调用拷贝构造函数，等价于 Person p8(p1);

    // 多参数构造函数的隐式构造法需要使用花括号进行初始化，否则会调用单参数构造函数\
    // 如果对应构造函数加了 explicit 关键字，则无法使用隐式构造法进行初始化
    Person p9 = {50, "Lucy"};  // 调用有参构造函数，等价于 Person p9(50, "Lucy");
    
    return 0;
}
