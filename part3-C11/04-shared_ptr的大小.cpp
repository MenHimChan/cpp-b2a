#include <bits/stdc++.h>

using namespace std;

void test() {
    shared_ptr<int> sp = make_shared<int>(100);
    cout << sizeof(sp) << endl;         // 16 = 1个原始指针（8B），管理指向的对象 + 1个控制块指针，指向包含引用计数的控制块 （8B）
}

int main() {
    test();
    return 0;
}