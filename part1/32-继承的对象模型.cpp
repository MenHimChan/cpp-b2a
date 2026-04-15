#include <iostream>

using namespace std;

class father {
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;

};

class son : public father {
private:
    int c;
};

void test() {
    // 因为对象里会包含父类的所有非静态成员，包含 private 成员。
    // public/protected/private 只影响访问权限，不影响对象内存是否存在
    son s1;
    cout << sizeof(s1) << endl;         // 16 = 12(父类) + 4(子类) 
}

int main() {
    test();
    return 0;
}