#include <iostream>

using namespace std;

class Auditor;

class Bank {
    // 允许该类的所有成员函数作为友元访问
    // bank的private 及 protected属性
    friend Auditor;  

private:
    double m_balance;

public:
    Bank(double balance) : m_balance(balance) {}
};

// 
class Auditor {
public:
    // 承诺不修改非静态属性
    void CheckBalance(const Bank& bk) const {
        cout << "bk.m_balance : " << bk.m_balance << endl;
    }

    void setBalance(Bank& bk, double amount) {
        bk.m_balance = amount;
    }
};

int main() {
    Bank bk(1000);
    Auditor aud;
    aud.CheckBalance(bk);
    aud.setBalance(bk, 199);
    aud.CheckBalance(bk);

    return 0;
}