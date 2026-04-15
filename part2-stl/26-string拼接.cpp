#include <bits/stdc++.h>

using namespace std;

void test() {   
    string str1 = "123";
    str1 += "4";
    cout << str1 << endl;           // 1 2 3 4

    str1.append("abc");
    cout << str1 << endl;           // 1 2 3 4 a b c
    str1.append(3,'d');             // .append(n, "123")非法
    cout << str1 << endl;           // 1 2 3 4 a b c d d d 

    string str2 = "abcde";
    str1.append(str2, 1, 3);        // 1 2 3 4 a b c d d d b c d
    cout << str1 << endl;
}

int main() {
    test();
    return 0;
}