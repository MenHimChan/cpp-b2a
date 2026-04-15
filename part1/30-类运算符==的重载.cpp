#include <iostream>
#include <cstring>

using namespace std;

class MyString {
    friend ostream& operator<<(ostream &os, const MyString &mystr);

private:
    char* m_str;

public:
    MyString(const char* str);                      // 只允许通过串字符串字面量构造
    MyString(const MyString& other) = delete;       // 不允许 Mystring p1(p2);
    MyString& operator=(const MyString&) = delete;  // 不允许 p2 = p1;
    bool operator==(const MyString& other) const;
    ~MyString();
};

bool MyString::operator==(const MyString& other) const {
    if(strcmp(this->m_str, other.m_str) == 0) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream &os, const MyString &mystr) {
    os << mystr.m_str;
    return os;
}

MyString::MyString(const char* str) {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

MyString::~MyString() {
    delete[] m_str;
}

int main() {
    MyString mystr1("123");
    MyString mystr2("123");

    cout << "mystr1 == mystr2 : " << (mystr1 == mystr2) << endl; 

    return 0;
}