#include <bits/stdc++.h>

using namespace std;

class Test {
public:
    Test(int i) : val(i) {cout << "Test(int i) " << endl;}
    ~Test() {cout << "~Test() " << endl;}
    void run() {cout << "Calling run()  !" << endl;}
    int val;
};

void useOnly(Test* ptr) {
    if (ptr) ptr->run();        
}

void takeOwnerShip(unique_ptr<Test> uptr) {
    uptr->run();
}

void test() {
    // release()： “净身出户” 切断智能指针与对象之间的联系。智能指针不再管理该对象，但对象不会被销毁。
    unique_ptr<Test> uptr1 = make_unique<Test>(10);
    Test* ptr = uptr1.release();                // 释放所有权给原始指针，自身已不管该空间
    cout << (*ptr).val << endl;
    if(uptr1 == nullptr) cout << "uptr = null" << endl; // 原来的智能指针已经空了

    // reset()： “推倒重来” 销毁当前管理的对象（如果有的话），并（可选地）接管一个新的原始指针
    unique_ptr<Test> uptr2 = make_unique<Test>(100);
    uptr2.reset(new Test(19));                  // 释放
    cout << (*uptr2).val << endl;               // 19

    // get() —— “只看不拿” 获取指向对象的原始指针，但所有权依然留在智能指针手里。
    // 一般是为了兼容C库，接收原始指针，千万不要对 get() 拿到的指针执行 delete。
    Test* raw_ptr = uptr2.get();
    cout << (*raw_ptr).val << endl;             // 19
    
    // 以unique_ptr传参
    // 只读方式
    useOnly(uptr2.get());                   // 执行：Calling run()  !

    // 转移所有权方式
    takeOwnerShip(std::move(uptr2));        
    if(nullptr == uptr2) cout << "uptr2 已空 ！ " << endl;

}

int main() {
    test();
    return 0;
}