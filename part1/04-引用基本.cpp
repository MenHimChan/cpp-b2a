#include <iostream>

using namespace std;

// 不能返回局部变量的引用
int& func() {
    int x = 10; // 局部变量
    return x;   // 返回局部变量的引用，危险！
}

// 引用类型的函数调用可以作为左值
int& getElem(int idx) {
    static int arr[5] = {1, 2, 3, 4, 5}; // 静态数组，生命周期贯穿整个程序
    return arr[idx]; // 返回数组元素的引用
}

int main() {
    int a = 100;
    int& b = a;

    // a b 的地址应该相同，因为 b 是 a 的引用
    cout << &a << " " << &b << endl; 

    // getElem函数可以作为左值使用
    getElem(2) = 10; // 修改数组元素的值
    cout << getElem(2) << endl; // 输出修改后的值，应该是 10
    getElem(2) = 20; // 再次修改数组元素的值
    cout << getElem(2) << endl; // 输出修改后的值，应该是 20

    return 0;
}