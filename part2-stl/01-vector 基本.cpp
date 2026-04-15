#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void callback(int i) {
    cout << i;
}

void test() {
    // 声明一个vector容器，存储int类型数据
    vector<int> v;

    // 插入数据
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    
    cout << "v 容器个数 ； " << v.size() << endl;
    cout << "vector[0] : " << v[0] << endl;

    // .data() 返回底层数组的指针
    cout << "v.data() : " << *v.data() << endl;

    // 遍历1
    // for 循环
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }

    // for_each
    for_each(v.begin(), v.end(), callback);

    // 获取元素数量
    cout << endl;
}

int main() {
    test();
    return 0;
}
