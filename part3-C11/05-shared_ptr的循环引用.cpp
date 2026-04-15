#include <bits/stdc++.h>

using namespace std;

class B;

class A{ 
public:
    ~A() {cout << "~A() is calling ! " << endl;}
    // shared_ptr<B> m_ptr;             
    weak_ptr<B> m_ptr;              // 采用weak_ptr就能正常析构了
};

class B{
public:
    ~B() {cout << "~B() is calling ! " << endl;}
    shared_ptr<A> m_ptr;
};


void test() {
    shared_ptr<A> sp2A(new A());
    shared_ptr<B> sp2B(new B());
    cout << sp2A.use_count() << endl;           // 1
    cout << sp2B.use_count() << endl;           // 1

    sp2A->m_ptr = sp2B;                         // A对象中的shared_ptr<B> m_ptr指向B对象
    sp2B->m_ptr = sp2A;                         // B对象中的shared_ptr<A> m_ptr指向A对象

    cout << sp2A.use_count() << endl;           // 2
    cout << sp2B.use_count() << endl;           // 2
}

int main() {
    test();
    return 0;
}