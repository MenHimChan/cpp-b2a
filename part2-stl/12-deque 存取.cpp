#include <bits/stdc++.h>

using namespace std;

void printdeq(deque<int>& v) {
    for(deque<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    deque<int> dq1{1,2,3};

    //  operator[], at() （支持随机访问）
    cout << dq1.at(0) << endl;          // 1
    cout << dq1[1] << endl;             // 2

    // front back
    cout << dq1.front() << endl;        // 1
    cout << dq1.back() << endl;         // 3

    // deque排序
    sort(dq1.begin(), dq1.end(), [] (int a, int b) {return a > b;});
    printdeq(dq1);                      // 3 2 1
}

int main() {
    test();
    return 0;
}   
