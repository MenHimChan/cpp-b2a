#include <bits/stdc++.h>

using namespace std;

void printlist(const list<int>& lst) {
    for(auto it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


void test() {
    list<int> lst{100,1,3,10,7,101,56};

    // 排序，不能用stl中的sort
    // sort(lst.begin(), lst.end(), [] (int a, int b) {
    //     return a > b;
    // });
    // 要用list自带的sort函数
    lst.sort([] (int a, int b) {return a > b;});
    printlist(lst);         // 101 100 56 10 7 3 1 

    // list 反转
    lst.reverse();      
    printlist(lst);         // 1 3 7 10 56 100 101
}

int main() {
    test();
    return 0;
}