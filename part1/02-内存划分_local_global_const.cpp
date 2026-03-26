#include <iostream>
#include <bitset>

using namespace std;

int g_a = 10; // 全局变量
int g_b = 20; // 全局变量
const int c_g_a = 30; // 全局常量
const int c_g_b = 40; // 全局常量

int main() {
    int a = 10;
    int b = 20;
    static int s_c = 30, s_d = 40;         // 静态局部变量
    const int e = 50;                      // 常量局部变量

    // 普通局部变量
    cout << "&a: " << &a << ", &b: " << &b << endl;
    // 全局变量
    cout << "&g_a: " << &g_a << ", &g_b: " << &g_b << endl;
    // 静态局部变量
    cout << "&s_c: " << &s_c << ", &s_d: " << &s_d << endl;
    // 全局常量 & 字符串字面量
    cout << "&c_g_a: " << &c_g_a << ", &c_g_b: " << &c_g_b << ", &\"hello world\": " << &"hello world" << endl;                 

    // 常量局部变量
    cout << "&e: " << &e << endl;
}
