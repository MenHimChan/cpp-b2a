#include <bits/stdc++.h>

using namespace std;

class Test {
private:
    vector<int> vec;
public:
    Test() : vec({4,12,512,591,1,10}) {}
    ~Test() = default;

    // 捕获private 中的
    void printTest(void) {
        [this] () {
            for_each(this->vec.begin(), this->vec.end(), [] (int a) { cout << a << ' '; });
        }();

        // 错误示范： 不能直接访问vec
        // [] () {
        //     for_each(vec.begin(), vec.end(), [] (int a) { cout << a << ' '; });
        // }();
        
        // = 默认捕获了this
        [=] () {
            for_each(this->vec.begin(), this->vec.end(), [] (int a) { cout << a << ' '; });
        }();
    }

    // 内层想用this，必须外层捕获了this
    void NestedCapture() {
        auto outer_lambda = [this]() {
            for (auto &x : this->vec) {

                auto inner_lambda = [this] () {
                    // 靠 this 访问类成员，间接拿到值
                    cout << this->vec[0] << ' ';
                };
                inner_lambda();
            }
        };

        outer_lambda();
    }
};

void test() {
    int q = 1000;
    {
        int i = 100, j = 200;
        double k = 3.01;

        // 值捕获 捕获一个变量
        auto f1 = [q] () {cout << q << endl;};      // 1000
        f1();

        // 值捕获 两个变量
        auto f2 = [i, k] () {cout << i << ' ' << k << endl;};     // 100 3.01
        f2();

        // 值捕获所有变量
        auto f3 = [=] () {cout << i << ' ' << j << ' ' << k << endl;};      // 100 200 3.01
        f3();

        // 引用捕获所有变量
        [&] () {i++; cout << i << ' ' << j << ' ' << k << endl;}();         // 101 200 3.01

        // 无法捕获其他函数中的变量
        // [var_In_main] () {} ();
    }
}

void test02() {
    Test tst;
    tst.printTest();
}

void test03() {
    Test tst;
    tst.NestedCapture();
}

int main() {
    int var_In_main = 114514;
    // test();
    test03();
    return 0;
}