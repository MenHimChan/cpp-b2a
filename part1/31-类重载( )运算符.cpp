#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

// 💡 编程挑战：区间过滤器 (Range Filter)

class RangeFilter{
private:
    int m_min, m_max;

public:
    RangeFilter(int min, int max);
    bool operator()(int num);

};

RangeFilter::RangeFilter(int min, int max) : m_min(min), m_max(max) {}

bool RangeFilter::operator()(int num) {
    return (num >= m_min && num <= m_max);
}


int main() {
    vector<int> nums = {5, 12, 18, 25, 60, 80, 110};
    RangeFilter rf1(10, 20), rf2(50, 100);

    cout << "rf1(50) : " << rf1(50) << endl;
    cout << "rf2(100) : " << rf2(100) << endl;

    // 好处是配合stl一起使用
    int count1 = count_if(nums.begin(), nums.end(), rf1);

    cout << count1 << endl;

    return 0;
}