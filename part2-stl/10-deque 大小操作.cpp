#include <bits/stdc++.h>

using namespace std;

void printdeq(deque<int>& v) {
    for(deque<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {

    // 判空: .empty
    deque<int> dq1;
    cout << dq1.empty() << endl;        // 1
    dq1 = deque<int> {1,2,3,4};
    cout << dq1.empty() << endl;        // 0

    // 大小 .size
    cout << dq1.size() << endl;         // 4

    // 没有capacity概念

    // resize： 重新指定size大小
    // resize(n); => 将deque的size设置为n
    // 当前比n小，补0； 当前比n大，截断
    deque<int> dq2{1,2,3,4,5};
    dq2.resize(10);
    printdeq(dq2);                      // 1 2 3 4 5 0 0 0 0 0 (补0)
    dq2.resize(3);  
    printdeq(dq2);                      // 1 2 3 (截断)

    // resize(n, m) => 将deque的size设置为n
    dq2.resize(5, 5);                   // 增长，空缺位置补5         
    printdeq(dq2);                      // 1 2 3 5 5
    dq2.resize(3, 5);                   // 增长，空缺位置补5         
    printdeq(dq2);                      // 1 2 3    
}

int main() {
    test();
    return 0;
}