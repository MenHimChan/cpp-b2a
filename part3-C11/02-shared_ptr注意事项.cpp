#include <bits/stdc++.h>

using namespace std;

class CTest {
public:
    CTest() { std::cout << "CTest 构造" << std::endl; }
    ~CTest() { std::cout << "CTest 析构" << std::endl; }
};

void test01() {
    // 不允许用同一个裸指针构造两个shared_ptr
    int* p = new int{100};
    shared_ptr<int> sp1(p);
    cout << sp1.use_count() << endl;        // 1
    shared_ptr<int> sp2(p);
    cout << sp1.use_count() << endl;        // 1

}

void test02() {
      // 1. 获取一个原始指针
    CTest* rawPtr = new CTest();

    {
        // 2. 第一次构造：sp1 认为它拥有这块内存，引用计数为 1
        std::shared_ptr<CTest> sp1(rawPtr);
        std::cout << "sp1 引用计数: " << sp1.use_count() << std::endl;

        {
            // 3. 错误操作：再次用 rawPtr 构造 sp2
            // 注意：sp2 无法感知 sp1 的存在，它会开启一个新的引用计数，计数也为 1
            std::shared_ptr<CTest> sp2(rawPtr);
            std::cout << "sp2 引用计数: " << sp2.use_count() << std::endl;

        } // <--- 重点：sp2 离开作用域，引用计数归零，释放 rawPtr 指向的内存
        
        std::cout << "sp2 已销毁" << std::endl;

    } // <--- 崩溃点：sp1 离开作用
}

int main() {
    test01();
    test02();
    return 0;
}

