#include <iostream>

using namespace std;

// 运算符： 修改自身型必须返回引用
// 代表选手：+=、-=、*=、/= 以及 前置 ++ / --。

class Counter {
    friend ostream& operator<<(ostream& os, const Counter& cter);
private: 
    int m_num;
public:
    Counter(int initval = 0) : m_num(initval) {}
    Counter& operator++();          // 默认是obj++;
    Counter operator++(int);        // 默认是++obj
};

// cout << cter = operator<<(cout, cter)
ostream& operator<<(ostream& os, const Counter& cter) {
    os << "cter.m_num : " << cter.m_num;
    return os;
}

// ++cter ： 直接返回递增之后的值
// 前置递增： 返回引用
Counter& Counter::operator++() {
    this->m_num++;
    return *this;
}

// cter++ : 整个表达式的值是递增之前的
// 后置递增，返回值
Counter Counter::operator++(int) {
    Counter retval = *this;
    this->m_num++;
    return retval;
}

int main() {
    // 整型数据的表现：
    int i = 0;
    cout << i << endl;
    cout << i++ << endl;
    cout << ++i << endl;

    cout << "------------------------------------" << endl;

    Counter cter;
    cout << cter << endl;
    cout << cter++ << endl;         // cter++ = retval (retval 的值拷贝给 cter++ 这个式子)
    cout << ++cter << endl;         
    return 0;
}