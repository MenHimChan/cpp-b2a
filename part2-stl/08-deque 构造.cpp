#include <bits/stdc++.h>

using namespace std;

void printdeq(deque<int>& v) {
    for(deque<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    // deque<type> dq(n);   ==> n个0
    deque<int> dq1(10);  
    printdeq(dq1);           // 0 0 0 0 0 0 0 0 0 0

    // deque<type> dq(n,m); ==> n个m
    deque<int> dq2(10,1);  
    printdeq(dq2);           // 1 1 1 1 1 1 1 1 1 1 

    // deque<type> dq{1,2,3}; ==> 直接初始化
    deque<int> dq3{10,20,30}; 
    printdeq(dq3);           // 10 20 30

    // 区间构造
    vector<int> v{1,2,3};
    deque<int> dq4(v.begin(), v.end());
    printdeq(dq4);           // 1 2 3
}

// 将 std::deque 视为 std::vector 在功能上的扩充
// 可以直接无缝替换的 API：
// push_back(), pop_back()
// operator[], at() （支持随机访问）
// size(), empty(), clear(), resize()
// begin(), end(), insert(), erase()

int main() {
    test();
    return 0;
}