// ① 左值 (lvalue - locator value)
// 定义：有名字、有固定地址、可以取地址 (&) 的表达式。
// 例子：变量名 i、函数名、返回引用的函数调用、arr[i]。
// 生命周期：通常较长，直到作用域结束。

// ② 纯右值 (prvalue - pure rvalue)
// 定义：没有名字、没有固定地址、不能取地址。它们通常是运算的中间结果或字面量。
// 例子：字面量 10、true、表达式结果 a + b、返回值的函数调用（非引用类型）。
// 生命周期：非常短，通常在表达式结束后立即销毁。

// ③ 将亡值 (xvalue - expiring value)
// 定义：这是 C++11 新引入的。它是有地址的，但它标志着对象资源即将被释放或移动。
// 例子：std::move(x) 的返回值、返回右值引用的函数调用。
// 意义：它是连接“拷贝”与“移动”的桥梁，告诉编译器：“这个东西虽然有地址，但你可以放心去‘偷’它的资源”。


#include <bits/stdc++.h>

using namespace std;

void test() {
    // 左值 left value ，lvalue
    // 有明确内存地址，或者有名字的对象
    // 可以对其取地址
    int lval = 10;
    int* p1 = &lval;         // 可以对左值取地址
    auto f1 = [&] (int a, int b) -> int& {
        lval = lval + a + b; 
        return lval;
    };
    int* p2 = &f1(114,514);         // f返回值为引用类型，可以取地址
    cout << "p1 : " << p1 << " p2 : " << p2 << endl;    // p1 : 0x7fffffffdac4 p2 : 0x7fffffffdac4

    // 纯右值 prvale
    // 没有标识符，无法取地址运算的零食数据
    // 1 各种字面量: 10 , true, 'a'
    // 2 算术表达式的结果，如a + b
    // 3 非引用返回值类型的函数
    auto f2 = [] (string input_str) -> string {
        return input_str;
    };
    // &f2("123");             // 报错： taking address of rvalue [-fpermissive]gcc
    
    // 将亡值 xvalue 
    // 通常由 ： 1 返回右值引用的函数 2 move函数返回
    string str1 = "string";
    string& l_ref2 = str1;
    string&& r_ref1 = move(str1);       // 右值引用绑定在move函数的返回值上   
    cout << r_ref1 << " " << l_ref2 << endl;             // string string
    l_ref2 += "123";
    cout << r_ref1 << " " << l_ref2 << endl;             // string123 string123
    
    string str2 = move(str1);           // 移动构造函数触发移动，str2接管资源
    // 资源已经被str2接管
    cout << str2 << endl;               // string123
    cout << "str1 : "  << str1 << " " << "r_ref1 : "        // 均为空
    <<  r_ref1 << "l_ref2: " << l_ref2 << endl;

    /////////////////////////////////////////////////////////////////////
    // 两种引用本质区别在于，
    // 左值引用： 左值引用只能绑定左值
    int l_val = 114514;
    int& l_ref = l_val;         

    // 右值引用： 只能绑定右值或将亡值
    int&& r_ref2 = 20;
    r_ref2++;
    cout << r_ref2 << endl;
}

int main() {
    test();
    return 0;
}