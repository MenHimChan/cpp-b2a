#include <bits/stdc++.h>

using namespace std;

class ctest{
public:
    ctest(int i) {}
    ctest(int i, int j) {}
    ctest() { cout << "调用 ctest()" << endl; }
};

void test() {
    auto sp1= make_shared<ctest>(19);
    shared_ptr<ctest> sp2 = make_shared<ctest>();
    cout << sizeof(sp1) << endl;                // 16 = 一个指向对象的指针 + 一个指向控制块的指针
}

int main() {
    test();
    return 0;
}