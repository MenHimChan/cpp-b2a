#include <iostream>

using namespace std;

class DataPlan {
    friend ostream& operator<<(ostream& cout ,const DataPlan& dp);

private:
    double m_general;
    double m_directed;

public:
    DataPlan(double general = 0.0, double directed = 0.0);
    DataPlan operator+(const DataPlan& other) const;    // dp.operator+(other)
};

// 
DataPlan::DataPlan(double general, double directed) 
    : m_general(general), m_directed(directed) {}

// 重载 流插入运算符 ： <<
// 等价于 operator<<(cout, dp)
ostream& operator<<(ostream& os, const DataPlan& dp) {
    os << "[通用 ： " << dp.m_general << " | "
        << "定向 ： " << dp.m_directed << "]";
    return os;
}

DataPlan DataPlan::operator+(const DataPlan& other) const {
    DataPlan retval;
    retval.m_directed = this->m_directed + other.m_directed;
    retval.m_general = this->m_general + other.m_general;
    return retval;
}

int main() {
    DataPlan dp1(1.4, 90.8), dp2(10.1, 12.1), dp3;
    // d1 + dp2 等价于 d1.operator+(dp2) 
    // 等价于 operator+(this, dp2) 等价于 operator+(&dp1, dp2)
    dp3 = dp1 + dp2;        
    
    // 调用链：
    // operator<<(cout, dp3)
    // 进入ostream& operator<<(ostream& os, const DataPlan& dp) 
    // 传参： ostream& os = cout， const DataPlan& dp = dp3
    // 执行：     os << "[通用 ： " << dp.m_general << " | "
    //              << "定向 ： " << dp.m_directed << "]";
    // 等价于：   cout << "[通用 ： " << dp.m_general << " | "
    //              << "定向 ： " << dp.m_directed << "]";
    // return os; <=> return cout
    cout << dp3 << endl;

    return 0;
}