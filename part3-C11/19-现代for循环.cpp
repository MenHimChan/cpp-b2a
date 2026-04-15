#include <bits/stdc++.h>

using namespace std;

void test() {
    vector<string> fruits = {"apple", "banana", "cherry"};

    // 只读访问
    for (const auto& f : fruits) cout << f << " ";  // apple banana cherry 
    cout << endl;
    
    // 读写访问
    for(auto& f : fruits) f += "123";
    for (const auto& f : fruits) cout << f << " ";   // apple123 banana123 cherry123

    // 拷贝访问，f每轮都是新对象
    for(auto f : fruits) f += "1";
    for (const auto& f : fruits) cout << f << " ";   // apple123 banana123 cherry123

}

int main() {
    test();
    return 0;
}