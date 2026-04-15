#include <bits/stdc++.h>

using namespace std;

class Person{

public:
    string m_name;
    int m_age;
    Person(string name, int age) : m_name(name), m_age(age) {}
    ~Person() = default;
};

void printPersons(const vector<Person>& persons) {
    for (const auto& p : persons) {
        cout << "Name: " << p.m_name << ", Age: " << p.m_age << endl;
    }
}

void test() {
    vector<Person> v{
        {"Tom", 100},
        {"tiger", 101}
    };

    // 直接在后面构造
    v.emplace_back("doc", 99);
}

int main() {
    test();
    return 0;
}