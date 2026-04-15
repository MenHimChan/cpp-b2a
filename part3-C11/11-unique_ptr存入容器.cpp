#include <bits/stdc++.h>

using namespace std;

void test() {
    unique_ptr<int> uptr = make_unique<int>(114514);
    vector<unique_ptr<int>> vec;
    // vec.push_back(uptr);            // 错误，因为uptr没有拷贝构造函数
    vec.push_back(move(uptr));          // 正确
    if(uptr == nullptr) cout << "Is empty  !" << endl;
}

int main() {
    test();
    return 0;
}