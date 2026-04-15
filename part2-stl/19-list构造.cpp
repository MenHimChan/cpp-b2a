#include <bits/stdc++.h>

using namespace std;


void printlist(const list<int>& lst) {
    for(auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    // 默认构造
    list<int> lst1;
    printlist(lst1);

    // Fill Contrcutor 指定长度构造
    list<int> lst2(5);
    list<int> lst3(5,100);
    printlist(lst2);        // 0 0 0 0 0 
    printlist(lst3);        // 100 100 100 100 100 

    // range constructor 范围构造
    // list(beg_it, end_it);
    vector<int> v{1,2,3,4,5};
    list<int> lst4(v.begin(), v.end());
    printlist(lst4);        // 1 2 3 4 5

    // 拷贝构造
    list<int> lst5 = lst4;
    printlist(lst5);        // 1 2 3 4 5

    // 列表初始化
    list<int> lst6{1,2,3,4,5,6,7};
    printlist(lst6);        // 1 2 3 4 5 6 7

    // 挨个push back
    list<int> lst7;
    for(int i = 0; i < 10; i++) {
        lst7.push_back(i);
    }
    printlist(lst7);
}

int main() {
    test();
    return 0;
}