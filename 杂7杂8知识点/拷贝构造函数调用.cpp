#include <bits/stdc++.h>

using namespace std;

class Test{
public:
    // 拷贝构造 
    Test(const Test& other) {cout << "calling Test(const Test& other)" << endl;}
    Test() {cout << "Calling Test() " << endl;}
    Test& operator=(const Test& other) {cout << "Calling Test& operator=(const Test& other)" << endl;}
};

void test() {
    Test obj1, obj3;
    // 调用拷贝构造函数：
    Test obj2 = obj1;   // calling Test(const Test& other)
    Test obj4(obj1);    // calling Test(const Test& other)

    // 调用operator=构造函数
    obj3 = obj1;        // Calling Test& operator=(const Test& other)
}

int main() {
    test();
    return 0;
}