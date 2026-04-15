#include <bits/stdc++.h>

using namespace std;

void printmap(const map<int, int>& mp) { // 建议加上 const，因为打印不应修改原 map
    for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key : " << it->first << " , value : " << it->second << endl;
    }
}


void test() {
    map<int, int> mp;

    // 插入
    // insert({key, value})
    // insert(make_pair(key, value))
    // mp[key] = value;  key 不能重复，否则值会被覆盖
    mp.insert({1,1});
    mp.insert(make_pair(3,4));
    mp[2] = 7;              // 如果没有这个键就会自动插入
    mp[4];                  // 如果没有这个键就会自动插入，默认值为0
    printmap(mp);           // key : 1 , value : 1
                            // key : 2 , value : 7
                            // key : 3 , value : 4
                            // key : 4 , value : 0

    // 删除
    mp.erase(4);            // 按key删除
    printmap(mp);           // key : 1 , value : 1
                            // key : 2 , value : 7
                            // key : 3 , value : 4
    mp.erase(mp.begin());   
    printmap(mp);           // key : 2 , value : 7
                            // key : 3 , value : 4

    mp.erase(mp.begin(), mp.end());
    printmap(mp);           // 清空

}

int main() {
    test();
    return 0;
}