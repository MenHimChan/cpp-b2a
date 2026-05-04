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

void test02() {
    // lambda表达式的捕获列表
    int val = 100;

    // 捕获普通int，lambda 可拷贝构造
    auto lambda_copy = [val]() {
        std::cout << val << std::endl;
    };

    // 可以正常装入 std::function
    std::function<void()> func1 = lambda_copy;
    func1();                // 100

    // 连 std::function 自己也能拷贝
    std::function<void()> func2 = func1;
    func2();                // 100
}

void test03() {
    unique_ptr<int> up = std::make_unique<int>(200);            // 你往盒子里放东西，那东西也必须能复制，否则就会导致整个盒子不可复制

    // 捕获 unique_ptr，这个 lambda 拷贝构造被隐式删除
    auto lambda_moveonly = [p = std::move(up)]() {              // 捕获列表里用移动语义捕获了一个不可复制的对象
        std::cout << *p << std::endl;
    };

    lambda_moveonly();                                          // 200
    // std::function<void()>&& func = move(lambda_moveonly);    // 这行直接编译报错，不允许将不可复制的 lambda 存入 std::function
    // auto func2 = func;
}

int main() {
    // test();
    test03();
    return 0;
}