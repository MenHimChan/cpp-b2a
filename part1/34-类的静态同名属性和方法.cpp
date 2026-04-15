#include <iostream>

using namespace std;

// 总结：
// 子类与父类有同名方法/属性，子类会把父类的隐藏。
// 如果要调用父类的，则要加入作用域 Son_obj::Father.attr

class father {
public:
    static int num;
};

int father::num = 10;

class son : public father {
public:
    static int num;
};

int son::num = 20;

int main() {
    son s;
    cout << "s.num (通过子类实例) = " << s.num << endl;                    // 不加任何修饰时，访问的是子类自己的
    cout << "s.father::num (通过子类实例) = " << s.father::num << endl;    // 要访问父类，要加上作用域

    cout << "son::num (通过子类名访问) = " << son::num << endl;           // static属性整类一份，访问不需要通过对象
    cout << "father::num (通过父类名访问) = " << father::num << endl;

    // 如果要通过子类来访问父类全局属性如何操作？
    cout << "son::father::num (经子类作用域访问父类) = " << son::father::num << endl;

    return 0;
}
