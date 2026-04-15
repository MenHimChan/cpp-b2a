#include <iostream>
#include <cstdint>

using namespace std;

class Point {
public:
	Point(float xval); 
	virtual ~Point();
	float getx() const;            // 访问x的值
	static int PointCount();       // 获取当前程序中总共创建了多少个 Point 对象的实例。
    virtual void func() { cout << "func() calling !" << endl; }

    void Memorylayout() {

    }

protected:
	float _x;
	static int _point_count;
};

int Point::_point_count = 0;

Point::Point(float xval) : _x(xval) {
    _point_count++;
}

Point::~Point() {
    _point_count--;
}

float Point::getx() const {return _x;} 

int Point::PointCount() {return _point_count; }



typedef void (*FuncPtr)(Point* thiz);


// 含虚函数的内存布局
// 首地址
// ↓
// | vptr | 非静态属性a | 非静态属性b | ... |
void test_vptr_call(Point& obj) {
    cout << "\n--- 开始探测 vptr 并调用 func ---" << endl;

    // 1. 获取指向属性_x的指针
    Point* obj_ptr = &obj;
    float* _x_ptr = (float*)((uint64_t*)obj_ptr + 1);
    cout << "_x_ptr = : " << _x_ptr << endl;
    cout << "*_x_ptr = : " << *_x_ptr << endl; 
    
    // 2. 获取vptr
    uint64_t* vptr_ptr = (uint64_t*)obj_ptr;
    uint64_t* vtable = (uint64_t*)*vptr_ptr;        // 将*vptr_ptr中的东西视为指针

    cout << "obj 地址        : " << &obj << endl;
    cout << "vptr(虚表地址点): 0x" << hex << (uint64_t)obj_ptr << dec << endl;
    cout << "vtable[0]       : 0x" << hex << vtable[0] << dec << endl;
    cout << "vtable[1]       : 0x" << hex << vtable[1] << dec << endl;
    cout << "vtable[2](func) : 0x" << hex << vtable[2] << dec << endl;

    // 2. 按常见 ABI：析构相关通常在前两个槽位，第一个普通虚函数常在 index 2
    FuncPtr pFunc = (FuncPtr)vtable[2];

    // 3. 手动传 this 指针调用
    pFunc(&obj);
}

int main() {
    Point p(3.14f);
    test_vptr_call(p);

    return 0;
}