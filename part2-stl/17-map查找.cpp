#include <bits/stdc++.h>

using namespace std;

void printmap(const map<int, int>& mp) { // 建议加上 const，因为打印不应修改原 map
    for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key : " << it->first << " , value : " << it->second << endl;
    }
}

void test() {
    map<int, int> mp {
        {1,2},
        {3,10},
        {-1,119},
        {100,10},
        {1,100}             // map中不能有重复元素，插入失败
    };

    printmap(mp);           // key : -1 , value : 119
                            // key : 1 , value : 2
                            // key : 3 , value : 10
                            // key : 100 , value : 10

    // find(key) 
    if(mp.find(10) != mp.end()) {
        cout << "key 存在" << endl;
    } else {
        cout << "key 不存在" << endl;
    }
    // 返回迭代器
    cout << (*mp.find(-1)).first << endl;       // -1
    cout << (*mp.find(-1)).second << endl;      // 119
    

    // key个数统计 count: 对于map 只有0/1
    cout << mp.count(-1) << endl;               // 1
}

int main() {
    test();
    return 0;
}