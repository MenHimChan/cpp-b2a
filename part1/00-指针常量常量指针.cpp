#include <iostream>

using namespace std;

int main() {
    int const c = 190;
    int const d = 200;
    int a = 100;
    int b = 1000;

    // 常量指针： 指向常量的指针，指针本身可以改变，但不能通过该指针修改所指向的内容
    const int* p1 = &c;          // (const int)(*)  指向整形常量的指针，一般指针（float* ）
    p1 = &d;                     // p1 可以改变指向
                  
    // 指针常量： 被const 修饰了的指针变量，指针本身不可改变，但可以通过该指针修改所指向的内容
    int* const p2 = &a;        // (int*) const 常量指针，必须初始化
    // p2 = &b;                // 错误：p2 是常量指针，不能改变指向
    *p2 = 300;                 // p2 指向的内容可以改变

    return 0;

}