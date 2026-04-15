#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test() {
    vector<int> vec{1,2,3,4};

    // 数组访问方式
    cout << vec[0] << " " << vec[1] << endl;

    // .at方法
    cout << vec.at(0) << endl;
    cout << vec.at(1) << endl;

    // front back
    cout << vec.front() << " " << vec.back() << endl;
}

int main() {
    test();
    return 0;
}