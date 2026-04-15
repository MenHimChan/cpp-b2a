#include <iostream>

using namespace std;

class Person {
public:
    int m_age;
    int m_score;
    int m_height;

    Person(int age, int score, int height) : m_age(age), m_score(score), m_height(height) {}
};

class must_used_initializer_list {
public:
    const string m_name;
    int& ref;

    // 必须要用初始化列表的情况：
    // 1. const成员变量必须在初始化列表中进行初始化
    // 2. 引用成员变量必须在初始化列表中进行初始化
    must_used_initializer_list(int& r) : m_name("Tom"), ref(r) {}
};

int main() {
    Person p1(18, 90, 180);
    cout << "年龄：" << p1.m_age << endl;
    cout << "分数：" << p1.m_score << endl;
    cout << "身高：" << p1.m_height << endl;
    cout << "-----------------------------" << endl;

    int age_value = 110;
    must_used_initializer_list obj(age_value);
    cout << "名字：" << obj.m_name << endl;
    cout << "引用成员变量ref的值：" << obj.ref << endl;
    age_value = 120;                    // 修改age_value的值，看看obj.ref的值是否也会改变
    cout << "引用成员变量ref的值：" << obj.ref << endl;

    return 0;
}