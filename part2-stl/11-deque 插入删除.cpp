#include <bits/stdc++.h>

using namespace std;

void printdeq(deque<int>& v) {
    for(deque<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    deque<int> dq1{1,2};

    // 头插 尾插
    dq1.push_back(3);               // 1 2 3 
    printdeq(dq1);
    dq1.push_front(0);              // 0 1 2 3 
    printdeq(dq1);

    // 头删 尾删
    dq1.pop_back();                 // 0 1 2
    dq1.pop_front();                // 1 2
    printdeq(dq1);

    // Insert(it, val_insert)   
    dq1.insert(dq1.begin() + 1, 1000);   //
    printdeq(dq1);                       //  1 1000 2

    // Insert(pos_it, times, val_insert)  
    dq1.insert(dq1.begin() + 1, 2, 300);   //
    printdeq(dq1);                         //  1 300 300 1000 2

    // Insert(pos_it, beg_it, end_it)
    deque<int>::iterator beg_it = dq1.begin() + 3, end_it = dq1.end();  // 1000 2
    dq1.insert(dq1.begin(), beg_it, end_it);  
    printdeq(dq1);                         //  1000 2 1 300 300 1000 2

    // erase(beg, end)
    dq1.erase(dq1.begin(), dq1.begin() + 1);
    printdeq(dq1);                         //  2 1 300 300 1000 2

    /// erase(pos_it)
    dq1.erase(dq1.begin());
    printdeq(dq1);                          //   1 300 300 1000 2

    // clear() 清除所有
    dq1.clear();
}



int main() {
    test();
    return 0;
}