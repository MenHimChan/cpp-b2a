#include <iostream>

using namespace std;

void showval(const int& x) {
    // x = 100;                // 过不了编译
    cout << "Value: " << x << endl;
}

int main() {
    int x = 1000;
    showval(x); // 输出 1000
}
