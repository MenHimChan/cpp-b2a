#include <iostream>

using namespace std;

// 什么时候类内重载，什么时候类外重载？
// 左边不是我，必须写类外：如果左操作数不是你的类
// （比如 cout << c 或 10 + c），只能写在类外。
// 修改我自己，建议写类内：如果是改变对象状态（比如 +=、-=、++），
// 写在类内逻辑最顺。
class Complex {
    // 允许全局函数访问类的私有成员
    friend Complex operator+(const Complex& other, int integer);
    friend Complex operator+(int integer, const Complex& other);
    
private:
    double m_real;
    double m_imag;

public:
    Complex(double real = 0.0, double imag = 0.0);
    void display() const;           // 承诺不修改类的属性
    Complex operator+(const Complex& other) const; // 重载加法运算符
};

Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}

Complex Complex::operator+(const Complex& other) const{
    Complex tmp;
    tmp.m_real = this->m_real + other.m_real;
    tmp.m_imag = this->m_imag + other.m_imag;
    return tmp;
}

void Complex::display() const {
    cout << m_real << " + " << m_imag << "i" << endl;
}

// other： a + bi
// integer: c
// 左操作数： Complex other， 右操作数： int integer
Complex operator+(const Complex& other, int integer) {
    Complex tmp;
    tmp.m_real = other.m_real + integer;
    tmp.m_imag = other.m_imag;
    return tmp;
}

Complex operator+(int integer, const Complex& other) {
    Complex tmp;
    tmp.m_real = other.m_real + integer;
    tmp.m_imag = other.m_imag;
    return tmp;
}

int main() {
    Complex c1(3.0, 4.0), c2(1.1, 4.3);
    Complex c3 = c1 + c2;
    cout << "c3 = c1 + c2 = ";
    c3.display();
    cout << "c3 = c1 + 10 = ";
    c3 = c3 + 10;           // 不能写成 c3 = 10 + c3，因为没有重载 int + Complex 的运算符
    c3.display();

    return 0;
}
