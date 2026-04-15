#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cb_print(int i) {
    cout << i << ' ';
}

void test() {
    int arr[5] = {1,2,3,4,5};
    int arr2[3] = {4,5,100};

    // assign赋值
    // 会直接覆盖容器中的现有内容
    vector<int> v;
    v.assign(begin(arr), end(arr));
    for_each(v.begin(), v.end(), cb_print);
    cout << endl;
    
    v.assign(4, 10);
    for_each(v.begin(), v.end(), cb_print);

    // 直接用等号
    cout << endl << "-----------------------" << endl;
    vector<int> v2(begin(arr2), end(arr2));
    for_each(v2.begin(), v2.end(), cb_print);
    cout << endl;

    v2 = v;
    for_each(v2.begin(), v2.end(), cb_print);
}

int main() {
    test();
    return 0;
}