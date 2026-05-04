#include <bits/stdc++.h>

using namespace std;

void test() {
    // 1 c_str() : 只读访问
    // 函数返回一个指向常量字符的指针，指向字符串的第一个字符。这个指针可以用来访问字符串的内容，但不能修改它。
    string str = "Hello, World!";
    cout << str << endl;            // Hello, World!

    // 这个C风格串可以以通过下标访问每个字符，直到遇到字符串结束标志'\0'为止。
    const char* c_str = str.c_str();
    for(int i = 0; c_str[i] != '\0'; i++) {
        cout << c_str[i] << ' ';    // H e l l o ,   W o r l d !
    }
    cout << endl;

    // 2 .data() : 从c17开始，返回一个char* 指针，可以直接用来修改字符串内容
    // 函数返回一个指向常量字符的指针，指向字符串的第一个字符。这个指针可以用来访问字符串的内容，但不能修改它。
    char* data = str.data();
    data[0] = 'h';
    cout << str << endl;            // hello, World!

    // 3 &str[0] : 从c++11开始，返回一个char* 指针，可以直接用来修改字符串内容
    char* data2 = &str[0];
    data2[0] = 'H';
    cout << str << endl;            // Hello, World!
}


int main() {
    test();
    return 0;
}