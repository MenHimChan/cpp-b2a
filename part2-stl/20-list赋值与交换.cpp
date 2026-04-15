#include <bits/stdc++.h>

using namespace std;

void printlist(const list<int>& lst) {
    for(auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    list<int> lst1{1,2,3};

    // 赋值操作的作用是：丢弃当前容器的所有元素，并把另一个容器的元素拷贝（或移动）过来。
    // .assign(n, m) : n个m覆盖当前这个list
    lst1.assign(4,1);           
    printlist(lst1);            // 1 1 1 1

    // .assign(beg_it, end_it)
    vector<int> v{100,200,300,400};
    lst1.assign(v.begin(), v.end());
    printlist(lst1);            // 100 200 300 400

    // Operator=
    list<int> lst2 = lst1;
    printlist(lst2);            // 100 200 300 400

    // 交换两个容器 swap
    list<int> lst3 = {114,514};
    lst2.swap(lst3);
    printlist(lst3);            // 100 200 300 400
    printlist(lst2);            // 114 514 
}   

int main() {
    test();
    return 0;
}