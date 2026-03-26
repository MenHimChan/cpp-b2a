#include <iostream>
using namespace std;

// 函数重载：
// 1. 函数名相同
// 2. 参数列表不同，或参数个数不同，或参数类型不同，或参数顺序不同
// 3. 同一个作用域下
// 注意： 函数重载不能发生在返回值不同的情况下

void func() {
    cout << "func()" << endl;
}

// 仅仅只是返回值不同不构成函数重载
// int func() {
//     cout << "func(int a)" << endl;
//     return 0;
// }

// func_ref(a) 调用该函数
void func_ref(int &a) {
    cout << "func_ref(int &a)" << endl;
}

// 引用也可以作为重载条件
// func_ref(10);调用该函数
void func_ref(const int &a) {
    cout << "func_ref(const int &a)" << endl;
}

int main() {
    int a = 5;
    // func();

    func_ref(10);   // 10 是一个右值，不能绑定到 int &a 上
    func_ref(a);    // a 是一个左值，可以绑定到 int &a 上

    return 0;
}