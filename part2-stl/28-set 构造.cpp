#include <bits/stdc++.h>

using namespace std;

void printset(const set<int>& thisset) {
    // for(auto it = thisset.begin(); it != thisset.end(); it++) {
    //     cout << *it << " ";
    // }
    for_each(thisset.begin(), thisset.end(), [] (int val) {cout << val << " ";});
    cout << endl;
}

void printset(const set<int, greater<int>> thisset) {
    // for(auto it = thisset.begin(); it != thisset.end(); it++) {
    //     cout << *it << " ";
    // }
    for_each(thisset.begin(), thisset.end(), [] (int val) {cout << val << " ";});
    cout << endl;
}

void test() {
    // 1 初始化列表构造
    set<int> s1 {5,43,1,32};    // 会自动排序，默认升序
    printset(s1);               // 1 5 32 43

    // 2 拷贝构造
    set<int> s2(s1);            
    printset(s2);               // 1 5 32 43

    // 3 区间构造
    vector<int> v = {10, 20, 30};
    set<int> s3(v.begin(), v.end());
    printset(s3);               // 10 20 30

    // 4 自定义排序规则
    set<int, greater<int>> s4{100,1,2,3,4};
    printset(s4);               // 100 4 3 2 1

    // 5 空集合insert构造
    set<int> s5;
    s5.insert(1);
    s5.insert(114);             
    s5.insert(514);
    s5.insert(251);
    printset(s5);               // 1 114 251 514
}

int main() {
    test();
    return 0;
}