#include <iostream>
using namespace std;

int main() {
    int b = 2, c = 3;

    int& r = (b = c);  // 把表达式结果绑定到引用

    // (b = c的值是b)
    cout << &r << endl;     // 0x7fffffffdb88
    cout << &b << endl;     // 0x7fffffffdb88
    cout << &c << endl;    // 0x7fffffffdb8c
}