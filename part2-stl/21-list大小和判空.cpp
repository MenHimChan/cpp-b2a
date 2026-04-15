#include <bits/stdc++.h>

using namespace std;

void printlist(const list<int>& lst) {
    for(auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    // resize(n)  resize(n,m)   ： resize成n大小，size = n
    list<int> lst1{1,2,3,4,5};
    lst1.resize(3);     
    printlist(lst1);            // 截断: 1 2 3

    lst1.resize(5, 100);        
    printlist(lst1);            // 1 2 3 100 100 （补的100）

    // 判空.empty

    // 大小
    cout << lst1.size() << endl;    // 5
}

int main() {
    test();
    return 0;
}