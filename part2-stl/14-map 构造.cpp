#include <bits/stdc++.h>

using namespace std;

void printmap(const map<string, int>& mp) { // 建议加上 const，因为打印不应修改原 map
    for(map<string, int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key : " << it->first << " , value : " << it->second << endl;
    }
}

void printmap(const map<int, int>& mp) { // 建议加上 const，因为打印不应修改原 map
    for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key : " << it->first << " , value : " << it->second << endl;
    }
}

void test() {
    // 声明： map<const key, val> mp
    // map中的元素都是pair

    // 列表初始化
    map<string, int> mp1{           // 默认按key的升序排序
        {"ydh", 24},
        {"cdm", 25}
    };

    printmap(mp1);

    // 拷贝构造
    map<string, int> mp2(mp1);
    printmap(mp2);

    // 迭代器范围构造
    vector<pair<string, int>> v = {{"a",1}, {"b",2}};
    map<string, int> mp3(v.begin(), v.end());
    printmap(mp3);                          // key : a , value : 1
                                            // key : b , value : 2

    // 逐个插入构造
    map<string, int> mp4;
    mp4.insert({"c", 3});
    mp4.insert(pair<string, int>("d",4));
    printmap(mp4);                          // key : c , value : 3
                                            // key : d , value : 4

    // 内部排序是默认key升序
    map<int, int> mp5{
        {10, 1},
        {9, 2},
        {3, 4},
        {11, 5}
    };
    printmap(mp5);          // key : 3 , value : 4
                            // key : 9 , value : 2
                            // key : 10 , value : 1
                            // key : 11 , value : 5
}

int main() {
    test();
    return 0;
}