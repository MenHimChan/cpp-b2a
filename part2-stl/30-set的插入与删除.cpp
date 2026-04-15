#include <bits/stdc++.h>

using namespace std;

void printset(const set<int>& thisset) {
    // for(auto it = thisset.begin(); it != thisset.end(); it++) {
    //     cout << *it << " ";
    // }
    for_each(thisset.begin(), thisset.end(), [] (int val) {cout << val << " ";});
    cout << endl;
}

void test() {
    set<int> s1{100,293,11,78,45,63};
    
    // 插入
    // insert
    s1.insert(114);
    printset(s1);           // 11 45 63 78 100 114 293 

    // emplace
    s1.emplace(514);        // 在容器的内存空间中就地构造
    printset(s1);           // 11 45 63 78 100 114 293 514

    // 删除
    // 指定迭代器删
    s1.erase(s1.begin());     
    printset(s1);           // 11 45 63 78 100 114 293 514
    
    // 迭代器区间删
    // s1.erase(s1.begin(), s1.begin() + 3);       // 不支持随机访问
    s1.erase(s1.begin(), next(s1.begin(), 3));     // 删掉从开头起的一共三个数
    printset(s1);           // 100 114 293 514

    // 根据值来删
    s1.erase(114);
    printset(s1);           // 100 293 514
}

int main() {
    test();
    return 0;
}