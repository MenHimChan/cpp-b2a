#include <bits/stdc++.h>

using namespace std;

void printlist(const list<int>& lst) {
    for(auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    list<int> lst{1,2,3,4,5,6,6};

    // 删： erase 接口
    // 1 l.erase(it)：删除 it 指向的元素。
    lst.erase(lst.begin());
    printlist(lst);             // 2 3 4 5 6 6

    // 2 l.erase(first, last)：删除 [first, last) 范围内的所有元素。
    // lst.erase(lst.begin(), lst.begin() + 2);         // 非法
    lst.erase(lst.begin(), next(lst.begin(), 2));       // 合法  4 5 6 6
    printlist(lst);

    // 删： remove接口
    lst.remove(6);      // 按值删除
    printlist(lst);     // 4 5
}

int main() {
    test();
    return 0;
}