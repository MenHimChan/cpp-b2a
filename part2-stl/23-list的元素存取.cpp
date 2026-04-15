#include <bits/stdc++.h>

using namespace std;

void printlist(const list<int>& lst) {
    for(auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    list<int> lst{1,2,1,4,51};

    cout << lst.front() << endl;        // 1 
    cout << lst.back() << endl;         // 51

    // 迭代器是双向迭代器
    auto it = lst.begin();
    it++;
    cout << *it << endl;                // 2
    it--;                              
    cout << *it << endl;                // 1

    // it += 2;                            // 非法
}

int main() {
    test();
    return 0;
}