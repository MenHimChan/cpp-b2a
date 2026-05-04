#include <bits/stdc++.h>

using namespace std;

void test() {
    //////////////////// 构造 /////////////////////
    // 默认构造
    string str1;        // 空串

    // C风格字符串常量构造
    string str2("Hello world");              
    const char* c_str = "Hello world";
    string str2_1(c_str, 5);                // Hello  从c_str的前5个字符构造

    // 拷贝构造
    string str3(str2);

    // string(n, m) n个m字符构造
    string str4(10, 'a');
    cout << str4 << endl;

    // 赋值： 用一个新值覆盖容器中的旧值
    // operator=
    string str5 = str4;
    string str6 = "12345";

    // assign赋值
    string str9 = "123";

    // 传入const char*赋值
    str9.assign("Hello C++");           // Hello C++
    cout << str9 << endl;

    // 截取赋值
    str9.assign("Hello C++", 5);       
    cout << str9 << endl;               // Hello  "Hello C++" 前5个字符

    // n个m赋值
    str9.assign(10, 'w');               
    cout << str9 << endl;               // wwwwwwwwww

    // 区间赋值 
    str9.assign(string("12345"), 0, 3);
    cout << str9 << endl;               // 1 2 3
}

void test02 () {
    string str1 = "123";
    str1.pop_back();      // 删除末尾字符
    cout << str1 << endl; // 12
}

int main() {
    // test();
    test02();
    return 0;
}