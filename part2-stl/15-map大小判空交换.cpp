#include <bits/stdc++.h>

using namespace std;

void printmap(const map<int, int>& mp) { // 建议加上 const，因为打印不应修改原 map
    for(map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key : " << it->first << " , value : " << it->second << endl;
    }
}

void test() {
    map<int, int> mp1{
        {10, 1},
        {9, 2},
        {3, 4},
        {11, 5}
    };

    // size empty 
    cout << mp1.size() << endl;         // 4
    cout << mp1.empty() << endl;        // 0

    map<int, int> mp2{
        {110, 11},
        {2, 9},
    };

    // 可以和他同类容器互换
    mp2.swap(mp1);
    cout << "mp1 : " << endl;
    printmap(mp1);

    cout << "mp2 : " << endl;
    printmap(mp2);

}

int main() {
    test();
    return 0;
}
