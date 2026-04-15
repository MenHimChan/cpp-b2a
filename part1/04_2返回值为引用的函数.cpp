#include <iostream>

using namespace std;

int g_x = 114514;


int& addgx(int add_num) {
    g_x += add_num;
    return g_x;         // 就是g_x本身
}

int main() {
    
    //1 引用型变量 绑定 引用返回值的真身
    int& g_x_ref = addgx(1000);     // int& g_x_ref = g_x;
    cout << g_x << endl;
    cout << g_x_ref << endl;

    //2 引用返回值函数直接作为左值使用
    addgx(1000) += 1000;            // 等价于 g_x += 1000
    cout << g_x << endl;
    cout << g_x_ref << endl;

    return 0;
}