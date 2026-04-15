#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cb_print(int i) {
    cout << i << ' ';
}

void test() {
    vector<int> v{1,2,3,4};

    // 1 尾插一个元素
    v.push_back(10);
    for_each(v.begin(), v.end(), cb_print);         // 1 2 3 4 10
    cout << endl;

    // 2 尾删一个元素
    v.pop_back();   
    for_each(v.begin(), v.end(), cb_print);         // 1 2 3 4
    cout << endl;

    // 3 指定位置插入 insert
    v.insert(v.begin() + 1, 10);
    for_each(v.begin(), v.end(), cb_print);         // 1 10 2 3 4
    cout << endl;

    // v.insert(it, n, m)
    // 指定位置n前面插入2次m元素
    v.insert(v.begin() + 1, 2, 90);
    for_each(v.begin(), v.end(), cb_print);         // 1 90 90 10 2 3 4
    cout << endl;

    // v.earase(it, n, m)
    // v.earase(it)
    v.erase(v.begin());
    for_each(v.begin(), v.end(), cb_print);         // 90 90 10 2 3 4 
    cout << endl;

    v.erase(v.begin(), v.begin() + 2);              // 从头开始删2个
    for_each(v.begin(), v.end(), cb_print);         // 10 2 3 4
    cout << endl;

    // v.clear
    v.clear();
    cout << v.size() << endl;                       // 0
}

int main() {
    test();
    return 0;
}