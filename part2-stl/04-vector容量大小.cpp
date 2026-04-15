#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cb_print(int i) {
    cout << i << ' ';
}

void test01() {
    vector<int> a;

    // 1 .empty() : 判空
    cout << a.empty() << endl;          // 1 => 空，因为此时没有元素

    for(int i = 0; i < 5; i++) a.push_back(i);   // vec = {0,1,2,3,4}
    cout << a.empty() << endl;

    // 2 .capacity: 容器的容量
    //   .size： 容器内的元素个数
    //   capacity >= size
    cout << a.capacity() << endl;       // 8 
    cout << a.size() << endl;           // 5

    // 多 push 5个数进去
    for(int i = 0; i < 5; i++) {
        a.push_back(i);
    }

    // capacity动态增加
    cout << a.capacity() << endl;       // 16 
    cout << a.size() << endl;           // 10
}

void test02() {
    // resize用法
    vector<int> v = {1,2,3};

    // resize(n)
    // resize: 当前容量 < n, 补0
    v.resize(5);
    for_each(v.begin(), v.end(), cb_print);     // 1 2 3 0 0

    cout << endl;

    // resize(n, m)
    // resize: 当前容量 < n, 补m
    v.resize(6, 9);     // 当前容量 < n  , 补9
    for_each(v.begin(), v.end(), cb_print);     // 1 2 3 0 0 9

    cout << endl;
    v.resize(3);        // 当前容量 > n，截断
    for_each(v.begin(), v.end(), cb_print);     // 1 2 3 0 0 9
}

int main() {
    // test01();
    test02();
    return 0;
}