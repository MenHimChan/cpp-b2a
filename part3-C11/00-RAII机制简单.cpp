#include <iostream>
using namespace std;

class test {
public:
    test() { cout << "test 对象出生了！" << endl; }
    ~test() { cout << "test 对象被析构了（内存释放）！" << endl; }
};


class CRAII
{
public:
    // 构造函数：获取资源
    CRAII(test* p)
    {
        m_pTest = p;
    }

    // 析构函数：释放资源
    ~CRAII()
    {
        delete m_pTest;    // 核心：对象销毁时，自动 delete 内存
        m_pTest = NULL;
    }

private:
    test *m_pTest;        // 内部存储的原始指针
};

int main()
{
    // 
    {
        // 1. 在堆上申请内存
        test* p = new test(); 
        
        // 2. 构造一个局部变量 r，并把 p 托付给它
        CRAII r(p); 
        
    } // <--- 关键：出了这个大括号，r 销毁，触发 ~CRAII()，自动 delete p

    // p是栈变量，出作用域自动释放；p指向的地方是堆内存，RAII机制释放

    return 0;
}