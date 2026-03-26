#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14;

class Father {
public:
    string m_name;
    int m_age;

protected:
    string Car = "BMW";

private:
    string m_password;
};

class Child : public Father {
public:
    void Guitar() {
        cout << "I can play guitar." << endl;
    }

    // 访问父类的保护成员Car
    void showCar() {
        cout << "My dad's car is: " << Car << endl; // 子类内部访问合法
    }
};

int main() {
    Child c;
    c.m_name = "Tom";
    c.m_age = 18;
    c.Guitar();
    c.showCar();            // 调用子类的成员函数
    return 0;
}