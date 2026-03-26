#include <iostream>

using namespace std;

int fun_add(int a, int b = 10, int c = 20) {
    return a + b + c;
}

// 1. 如果从某个位置开始有默认值，那么从这个位置开始后面的参数都必须有默认值
// ❌： int fun_add(int a, int b = 10, int c) 

// 2. 函数声明和函数定义中默认参数只能出现在一个地方，不能同时出现在函数声明和函数定义中
int fun_add2(int a, int b = 10, int c = 20);

int main() {
    cout << fun_add(1) << endl;          // 输出 31 (1 + 10 + 20)
    cout << fun_add(1, 2) << endl;       // 输出 23 (1 + 2 + 20)
    cout << fun_add(1, 2, 3) << endl;    // 输出 6 (1 + 2 + 3)

    return 0;
}

int fun_add2(int a, int b, int c) {
    return a + b + c;
}