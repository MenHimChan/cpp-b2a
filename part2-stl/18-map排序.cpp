#include <bits/stdc++.h>

using namespace std;

class cmpfun {
public:
    // bool cmp(a,b) 返回true，a在b前；返回false，b在a前
    // [a, b]:  升序=[a < b]
    //          降序=[a > b]
    bool operator()(int a, int b) const{
        return a>b;
    }
};

void printmap(const map<int, int, cmpfun>& mp) { // 建议加上 const，因为打印不应修改原 map
    for(map<int, int, cmpfun>::const_iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key : " << it->first << " , value : " << it->second << endl;
    }
}

void test() {
    map<int, int, cmpfun> mp{
        {1,2},
        {3,4},
        {5,6},
        {7,8},
        {9,10}
    };

    printmap(mp);
}

int main() {
    test();
    return 0;
}