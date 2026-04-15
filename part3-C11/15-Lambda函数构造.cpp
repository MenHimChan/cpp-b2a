#include <bits/stdc++.h>

using namespace std;

void test() {
    // 形式1 [捕获] (形参) -> 返回值类型 { 函数体 }     （完整形式）
    auto lambda_fun1 = [] (int a, int b) -> int {
        return a + b;
    };
    cout << lambda_fun1(10, 20) << endl;            // 30 

    // 形式2 [捕获] (形参) { 函数体 }                   （返回值编译器自动推导，省略->）
    auto lambda_fun2 = [] (int a) {
        cout << a << " ";
    };

    vector<int> vec{1,3,4,59,10};
    for_each(vec.begin(), vec.end(), lambda_fun2);      // 1 3 4 59 10

    // 形式3 [捕获] {函数体} （省略了括号）
    auto lambda_fun3 = []  {cout << "lambda_fun3 " << endl;};   // lambda_fun3
    lambda_fun3();

}

int main() {
    test();
    return 0;
}