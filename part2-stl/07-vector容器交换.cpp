#include <bits/stdc++.h>

using namespace std;

void printvec(vector<int>& v) {
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    vector<int> v1{1,2,3} ;
    vector<int> v2{5,1};

    printvec(v1);
    printvec(v2);

    v1.swap(v2);

    printvec(v1);
    printvec(v2);

}

int main() {
    test();
    return 0;
}