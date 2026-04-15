#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cb_print(int i) {
    cout << i << endl;
}

void test() {

    // 1 普通push back 构造
    // for(int i = 0; i < 10; i++) {
    //     v.push_back = arr[i]
    // }

    // 2 拷贝构造
    // vector<int> v1(v2); // 用v2构造v1

    // 3 列表初始化构造
    // vector<int> v1{1,2,3,4};

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    
    // 3 区间构造 vector(v.begin(), v.end())
    vector<int> v1(begin(arr1), end(arr1)), v2;
    for_each(v1.begin(), v1.end(), cb_print);

    // 4 vector(n, elem)      10 个 elem放进vector中
    vector<int> v3(10, 1);          
    for_each(v3.begin(), v3.end(), cb_print);

    // 5 vector(n)      
    vector<int> v4(15);
    for(const int& i : v4) cout << i << " "; // 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
}

int main() {
    test();
    return 0;
}