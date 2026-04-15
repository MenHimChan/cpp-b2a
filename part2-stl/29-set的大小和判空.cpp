#include <bits/stdc++.h>

using namespace std;

void printset(const set<int>& thisset) {
    // for(auto it = thisset.begin(); it != thisset.end(); it++) {
    //     cout << *it << " ";
    // }
    for_each(thisset.begin(), thisset.end(), [] (int val) {cout << val << " ";});
    cout << endl;
}

void test() {
    set<int> s1{210,12,129,234,19};
    cout << s1.size() << endl;          // 5
    cout << s1.empty() << endl;         // 0
}

int main() {
    test();
    return 0;
}