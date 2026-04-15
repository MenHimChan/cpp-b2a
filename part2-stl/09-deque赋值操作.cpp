#include <bits/stdc++.h>

using namespace std;

void printdeq(deque<int>& v) {
    for(deque<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    // operator= 赋值运算
    deque<int> dq1{1,2,3};
    deque<int> dq2(10);
    dq2 = dq1;               // 1 2 3
    printdeq(dq2);

    // assign： 先清空，再复制新值进来
    // assign(beg, end) beg end都是迭代器
    deque<int> dq3(10);
    vector<int> v{1,2,3,4,5};
    vector<int>::iterator beg = v.begin() + 2, end = v.end();
    printdeq(dq3);          // 0 0 0 0 0 0 0 0 0 0 
    dq3.assign(beg, end);
    printdeq(dq3);          // 3 4 5 

    // assign(n, m)  
    deque<int> dq4(3);
    dq4.assign(5,10);
    printdeq(dq4);          // 3 4 5 

}

int main() {
    test();
    return 0;
}