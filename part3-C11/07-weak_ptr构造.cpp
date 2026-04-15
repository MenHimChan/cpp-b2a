#include <bits/stdc++.h>

using namespace std;

void test() {
    shared_ptr<int> sp = make_shared<int>(18);
    cout << sp.use_count() << endl;         // 1

    // 1 通过shared ptr的对象构造 （因为shared_ptr和weak_ptr需要配套使用）
    weak_ptr<int> wp(sp);
    cout << sp.use_count() << endl;         // 1 
    cout << wp.use_count() << endl;         // 1 （返回指向同一块内存的shared_ptr的use——count）

    // 2 通过operaotr= 构造
    weak_ptr<int> wp1 = sp; 
    weak_ptr<int> wp2 = wp1;

    // =========================================================

    // 通过weak_ptr引用指向的对象： 

    // 1 不能直接解引用 weak_ptr
    // cout << *wp1 << endl;


    // 2 推荐做法： 线程安全的
    if(auto tmp_sp = wp1.lock()) {
        cout << *tmp_sp << endl;            // 18
    } else {
        cout << "wp1指向的内存区域已释放 " << endl;
    }

    // 2 或者：（但是多线程下可能不安全，!wp1.expired()和构造shared ptr不是原子的）
    if(!wp1.expired()) {
        shared_ptr<int> sptr(wp1);
        cout << *sptr << endl;              // 18
    } else {
        cout << "wp1指向的内存区域已释放 " << endl;
    }
}

int main() {
    test();
    return 0;
}