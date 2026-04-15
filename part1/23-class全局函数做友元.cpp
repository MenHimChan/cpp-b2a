#include <iostream>

using namespace std;

class Building {
    // 一般写类最前面，不需要加任何访问修饰符
    friend void good_friend(Building &b); // 声明友元函数

public:
    string m_sitting_room;
    string m_kichen;
    
    Building() : m_sitting_room("客厅"), m_kichen("厨房"), m_bed_room("卧室") {}
    ~Building() = default;

private:
    string m_bed_room;
};

// 友元函数可以访问类的私有成员: private and protected
void good_friend(Building &b) {
    cout << "好朋友访问: " << b.m_sitting_room << endl;
    cout << "好朋友访问: " << b.m_kichen << endl;
    cout << "好朋友访问: " << b.m_bed_room << endl; // 错误，无法访问私有成员
}

int main() {
    Building b;
    good_friend(b);
    return 0;
}