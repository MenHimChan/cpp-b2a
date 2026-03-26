#include <iostream>
#include <string>

using namespace std;

// 默认私有成员
class class1{
    int a = 100;
};

// 默认公有成员
struct struct1{
    int a = 100;
};

int main() {
    class1 c1;
    struct1 s1;
    // cout << "class1 a: " << c1.a << endl;   // error: 'int class1::a' is private within this context
    cout << "struct1 a: " << s1.a << endl;  // output: struct1 a: 100
    return 0;
}