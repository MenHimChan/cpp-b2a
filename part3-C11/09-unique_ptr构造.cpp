#include <bits/stdc++.h>

using namespace std;

class Test {
public:
    Test(int i) : val(i) { cout << "Test(int i) " << endl; }
    ~Test() { cout << "~Test() " << endl; }
    void run() {cout << "Calling run()  !" << endl;}
    int val;
};

void test() {
    // 1 工厂方法构造： 最安全最高效
    unique_ptr<Test> uptr1 = make_unique<Test>(10);
    uptr1->run();

    // 2 原始指针构造
    unique_ptr<Test> uptr2(new Test(19));
    cout << uptr2->val << endl;         // 19

    // 3 拷贝构造 & 赋值构造？
    // 不允许
    // unique_ptr<Test> uptr3(uptr2);
    // unique_ptr<Test> uptr3 = uptr2;

    // 4. 转移所有权 (移动构造)
    // std::move 将所有权从一个指针“转移”给另一个
    unique_ptr<Test> uptr3 = move(uptr1);
    if(uptr1 == nullptr) cout << "uptr1 已经为空" << endl;      // uptr1 已经为空
    uptr3->run();
}

int main() {
    test();
    return 0;
}