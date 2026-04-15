#include <iostream>
#include <cstring>

using namespace std;

// 编译器默认为class 提供operator= 的重载函数
// 2. 特殊接力型：必须返回引用
// 代表选手：=（赋值运算符）。
// 逻辑：正如我们刚聊过的 SystemLog，赋值运算符需要支持 a = b = c;

class SysLog{
    friend ostream& operator<<(ostream& os, const SysLog& sl);
private:
    char* m_content;

public:
    SysLog(const char* text);
    ~SysLog();
    SysLog(const SysLog& other);
    SysLog& operator=(const SysLog& other);
};

SysLog::SysLog(const SysLog& other) {
    // this->m_content = other.m_content;   // 浅拷贝
    m_content = new char[strlen(other.m_content) + 1];
    strcpy(m_content, other.m_content);
}

ostream& operator<<(ostream& os, const SysLog& sl) {
    os << sl.m_content;
    return os;
}

// 通过 = 运算符实现深拷贝
// 要实现 a = b = c 这样的链式操作
SysLog& SysLog::operator=(const SysLog& other) {
    // 先把原来的内存全部释放
    delete[] m_content;

    m_content = new char[strlen(other.m_content) + 1];
    strcpy(m_content, other.m_content);

    return *this;
}

SysLog::SysLog(const char* text) {
    m_content = new char(strlen(text) + 1);
    strcpy(m_content, text);
    // cout << "Calling Constrcutor, allocate mem for log ! " << endl;
}

SysLog::~SysLog() {
    if(m_content != nullptr) {
        delete[] m_content;
        m_content = nullptr;
    }
}

int main() {

    // 普通 = 运算符特性：
    int a = 1, b = 2, c = 3;
    a = b = c;
    cout << a << " " << b << " " << c << endl;

    cout << "-----------------------------------------" << endl;

    SysLog syslog1("Hello world");
    SysLog syslog2("111");
    SysLog syslog3("222");
    cout << syslog1 << endl;        // Hello world
    cout << syslog2 << endl;        // 111
    cout << syslog3 << endl;        // 222

    // SysLog syslog2 = syslog1;   // 这样调用的是拷贝构造函数
    syslog2 = syslog1 = syslog3;          // operator(&syslog2, syslog1)
    cout << "syslog : " << syslog2 << endl;

    return 0;
}