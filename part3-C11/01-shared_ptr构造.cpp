#include <bits/stdc++.h>
using namespace std;

void process(shared_ptr<int> sp, int priority) {

}

void test() {
    // 1 原始指针构造： 不允许通过同一个原始指针构造两个shared_ptr
    int* p = new int(10);
    shared_ptr<int> sp1(p);
    cout << *p << endl;         // 10
    cout << *sp1 << endl;       // 10

    // 2 拷贝构造: sp2和sp1共享所有权，use_count++
    shared_ptr<int> sp2(sp1);
    cout << *sp2 << endl;       // 10

    cout << sp2.use_count() << endl;    // 2
    cout << sp1.use_count() << endl;    // 2
    cout << sp1 << " " << sp2 << endl;  // 0x55555556aeb0 0x55555556aeb0

    // 3 operator= 拷贝构造，use count++
    shared_ptr<int> sp3 = sp2;          // 
    cout << sp1 << " " << sp2 << " " << sp3 << endl;  // 0x55555556aeb0 0x55555556aeb0
    cout << sp1.use_count() << endl;    // 3
    cout << sp2.use_count() << endl;    // 3
    cout << sp3.use_count() << endl;    // 3

    // 3 make_shared 构造（工厂方法）
    // 优势①： 内存分配一次，效率高
    shared_ptr<int> sptr = make_shared<int>(100);
    cout << *sptr << endl;              // 100
    // 优势②： 异常安全的构造
    process(shared_ptr<int>(new int{}), 19);        // 非异常安全
    process(make_shared<int>(10), 109);             // 异常安全构造

    // 移动构造
    // 移动后原指针变为null，不能解引用
    shared_ptr<int> sptr2 = move(sptr);
}

int main() {
    test();
    return 0;
}
