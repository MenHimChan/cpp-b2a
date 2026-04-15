#include <bits/stdc++.h>
using namespace std;

int func_add(int a, int b) {
    return a + b;
}

// 函数对象（仿函数）
class MyAdd {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

void test() {
    // 可调用对象： 只要一个东西能在它后面加上括号 () 并且传入参数来执行，就算是/
    // 一共四种 

    // 1 函数指针
    // 返回类型 (*函数指针名)(参数列表)
    // 现代cpp： auto fun_ptr = func;
    int (*fun_ptr)(int a, int b) = func_add;
    cout << fun_ptr(100,200) << endl;       // 300

    // 2 仿函数
    MyAdd myadd;
    cout << myadd(1,4) << endl;         // 5

    // 3 lambda表达式： [捕获列表] (参数列表) -> 返回类型 { 函数体 }
    auto lmbda = [](int a, int b) -> int {
        return a + b;
    };
    cout << lmbda(19, 20) << endl;      // 39

    // 4 普通函数
    // 如 printf()

    //////////////////////////////////////////////////////////////////////
    // std::function 可调用类型相同即可封装到一起
    // 1 包装器类型仅仅依赖于调用特征，而不依赖于可调用元素自身的类型
        // 调用特征： 返回值类型，形参输入
        // 可调用元素自身的类型： 如lambda表达式，函数指针，函数对象，对c++编译器都是不同类型
    // 2 构造方法
        // 如可通过func()方式调用，则这样写 ： function<retval(a, b)> = func;
    
    function<int(int, int)> op1 = func_add;
    cout << op1(100,200) << endl;       // 300

    function<int(int, int)> op2 = myadd;
    cout << op2(100,200) << endl;       // 300

    function<int(int, int)> op3 = lmbda;
    cout << op3(100,200) << endl;       // 300

    // 将相同调用类型的可调用对象封装到一起：
    vector<function<int(int, int)>> fun_vec;
    fun_vec.push_back(op1);
    fun_vec.push_back(op2);
    fun_vec.push_back(op3);
    fun_vec[0](100,200);                // 300
    fun_vec[1](100,200);                // 300
    fun_vec[2](100,200);                // 300
}

int main() {
    test();
    return 0;
}