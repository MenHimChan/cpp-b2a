#include <bits/stdc++.h>

using namespace std;

void test01() {
    // static_cast 的用法
    // 基本的数据类型之间的强制类型转化
    // 整形： short, int, long, long long, (bool, char)
    // 浮点： float, double, long double 
    
    // bool -> int
    bool val1 = true;
    int val2 = static_cast<int>(val1);
    cout << val2 << endl;                                   // 1

    // char -> int
    char val3 = 123;
    auto val4 = static_cast<int>(val3);
    cout << val3 << " " << val4 << endl;                    // { 123

    // int -> double
    int val5 = 114514;
    auto val6 = static_cast<double>(val5) * 0.1;
    cout << val6 << endl;

    // int -> double
    int val7 = 7;
    int val8 = 100;
    double val9 = static_cast<double>(val8) / val7;         // 14.2857
    cout << val9 << endl;
}

class Base {
public:
    virtual ~Base() = default;    
};

class Derived : public Base {};

// 核心使用场景：多态下行转换（Downcasting）
// 1 基类（父类）必须至少有一个虚函数（通常是 virtual ~Base()
// 2 只能用来转化指针或引用，不能用来转化基本数据类型
void test02() {
    // dynamic_cast()
    // dynamic_cast 不是“把Base变成Derived”，而是“检查它本来是不是 Derived，是就给你，不是就返回nullptr”。
    Base* p1 = new Derived;         // 父类指针指向子类对象
    Base* p2 = new Base;            // 父类指针指向父类对象

    Derived* d1 = dynamic_cast<Derived*>(p1);   // 成功，d1 非空
    Derived* d2 = dynamic_cast<Derived*>(p2);   // 失败，d2 == nullptr

    // 标准模板： 能转化成功就返回指向 Derived 的指针，转化失败就返回 nullptr
    if(d1 != nullptr) {
        cout << "p1 是 Derived 类型" << endl;    // p1 是 Derived 类型
    } else {
        cout << "p1 不是 Derived 类型" << endl;
    }

    if(d2 != nullptr) {
        cout << "p2 是 Derived 类型" << endl;
    } else {
        cout << "p2 不是 Derived 类型" << endl;    // p2 不是 Derived 类型
    }

    // dynamic_cast 不能用来转化基本数据类型
    // int val2 = dynamic_cast<double>(val1);     // 错误，
}

void test03() {
    // reinterpret_cast()
    // 1. 重新解释一个指针或引用的位模式，完全不考虑类型系统
    // 2. 主要用于底层编程，极其危险，除非你非常清楚自己在做什么，否则不要使用它。
    // 不能用的场景： 基本数据类型之间的转换，应该使用 static_cast 来进行类型转换。

    // a 指针 -> 指针: 可以把任何类型的指针转换成其他任何类型的指针
    int* p1 = new int(114514);
    char* p2 = reinterpret_cast<char*>(p1);   // 重新解释 p1 的位模式为 char*, 
    cout << *p2 << endl;                      // 输出R, 因为解引用 p2 得到的是 p1 指向的整数的第一个字节，114514 的二进制表示的第一个字节是 0x52（ASCII 'R'）

    // b 指针 -> 整数: 可以把指针转换成一个整数类型（通常是 uintptr_t 或 intptr_t），
    // uintptr_t 的语义就是“可容纳指针值的无符号整数类型”。
    // 但这通常没有什么实际意义，除非你在做一些非常底层的操作。
    uintptr_t addr = reinterpret_cast<uintptr_t>(p1);   // 将指针 p1 转换成一个整数地址
    cout << "p1 的地址: " << addr << endl;               // p1 的地址: 93824992325296 

    // c 整数 -> 指针: 可以把一个整数转换回指针类型，但这也是非常危险的，除非你非常确定这个整数确实是一个有效的指针地址。
    int* p3 = reinterpret_cast<int*>(addr);   // 将整数地址转换回指针类型
    cout << *p3 << endl;                      // 114514

    // d 引用 -> 引用: 可以把一个引用转换成另一个类型的引用
    int val = 1114;                                     // 0x 0000 045A
    int& ref_int = val;                                 
    char& ref_char = reinterpret_cast<char&>(ref_int);  // 重新解释ref_int的位模式为char&，得到一个对 val 的第一个字节0x5A的引用
    cout << ref_char << endl;                           // 输出： Z
    ref_char = 'A';                                     // 修改 ref_char 的值，实际上修改了val的第一个字节
    cout << val << endl;                                // 输出： 1089
}

void test04() {
    // const_cast()
    // 1. 用于添加或移除对象的 const 或 volatile 属性
    // 2. 只能用来转化指针或引用，不能用来转化基本数据类型
    // 3. 只能改变对象的 cv-qualifiers（const 和 volatile），不能改变对象的类型

    // a 移除 const
    const int val1 = 114514;
    int* p1 = const_cast<int*>(&val1);   // 移除 val1 的 const 属性，得到一个指向非 const int 的指针
    *p1 = 1919810;                       // 修改 p1 指向的值，实际上修改了 val1 的值（未定义行为）
    cout << val1 << endl;                // 输出：1919810

    // b 添加 const
    int val2 = 1919810;
    const int* p2 = const_cast<const int*>(&val2);   // 添加 val2 的 const 属性，得到一个指向 const int 的指针
    cout << *p2 << endl;                            // 输出：1919810
}

int main() {
    test03();
    return 0;
}

