#include <bits/stdc++.h>

using namespace std;

void test() {
    set<int> s1{110,231,114,514,10};

    // 查找 find 返回迭代器
    auto pos = s1.find(114);
    if(pos != s1.end()) {
        cout << *pos << endl;        // 114
    }

    // 统计元素个数count, 对于set来说只返回0/1，因为不允许重复元素
    int num = s1.count(10);
    cout << num << endl;             // 1
}

int main() {
    test();
    return 0;
} 