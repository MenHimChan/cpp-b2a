#include <bits/stdc++.h>

using namespace std;

void test() {
    string str1("abcdedeabc");

    // 左往右查找： find("substr", start_pos)
    int pos = str1.find("de", 0);   // 返回子串第一次出现的索引       
    cout << pos << endl;            // 3

    // 
    pos = str1.find("zz");          // -1 => 没找到
    cout << pos << endl;

    // rfind 从右往左找
    pos = str1.rfind("abc");        // 7
    cout << pos << endl;            

    // find_first_of找到第一个字符并返回下标
    pos = str1.find_first_of("d");
    cout << pos << endl;            // 3
}

int main() {
    test();
    return 0;
}