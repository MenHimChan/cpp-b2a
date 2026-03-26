#include <iostream>
#include <bitset>

using namespace std;

// 危险： 返回局部变量的地址，调用者使用后会导致未定义行为
int* ret_local_ptr() {
    int local_var = 42; // 局部变量
    return &local_var;   // 返回局部变量的地址（危险！）
}

int* ret_heap_mem() {
    int* heap_ptr = new int(42);        // 分配的时候直接堆内存初始化
    return heap_ptr;                    // 返回堆内存的地址（安全）
}

int main() {
    int a = 100;
    int *ptr = &a;                  // 获取局部变量的地址
    
    // 1. 分配单个int的堆内存，初始值随机（未初始化）
    int* p1 = new int;
    *p1 = 10;                       // 手动赋值
    cout << p1 << endl;             // 输出指针地址
    cout << ptr << endl;            // 输出局部变量地址（可能无效）
    cout << *p1 << endl;            // 输出：10


    // 2. 分配数组（堆数组）
    int* arr = new int[5]{1,2,3,4,5};  // C++11及以上支持列表初始化
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";  // 输出：1 2 3 4 5
    }
    cout << endl;

    // 必须释放堆内存！否则内存泄漏
    delete p1;       // 释放单个变量指向的地址
    delete[] arr;    // 释放数组指向的地址

    // 释放后将指针置空，避免野指针
    p1 = nullptr;
    arr = nullptr;

    return 0;
}
