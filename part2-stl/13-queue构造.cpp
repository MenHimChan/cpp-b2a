#include <bits/stdc++.h>

using namespace std;

void printqueue(const queue<int>& q) {
    queue<int> tmp = q;
    while(tmp.empty() != true) {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;
}

void test() {
    // queue的底层容器是deque, 可以用一个deque初始化一个queue
    deque<int> dq{1,2,3};
    queue<int> q1(dq);

    // operator= 支持赋值操作
    queue<int> q2 = q1;
    printqueue(q2);             // ------
    printqueue(q1);             // 3 2 1
                                // ------

    // 按顺序入队
    queue<int> q3;
    for(int i = 0; i < 3; i++) q3.push(i);  //      =====
    printqueue(q3);                         //      2 1 0  head
                                            //      =====
    // 数据存取
    cout << q3.back() << endl;      // 2
    cout << q3.front() << endl;     // 0
    cout << q3.size() << endl;      // 3
    cout << q3.empty() << endl;     // 0
}

int main() {
    test();
    return 0;
}