#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 静态多态： 通过函数的重载实现
// 动态多态： 通过基类接口，在运行时决定调用哪个子类实现
// 1 类继承 2 虚函数重写 3 父类指针指向子类对象

class SmartDevice {
protected:
    string name;
public:
    SmartDevice(string n) : name(n) {}
    
    virtual void activate() {
        cout << name << " 正在准备启动..." << endl;
    }

    // 建议养成好习惯：虚析构函数
    virtual ~SmartDevice() {} 
};


// 1 先构造父类子对象（这里是 SmartDevice(n)）
// 2 再构造子类自己的成员
// 3 最后执行子类构造函数体
// Light(string n) : SmartDevice(n)： 
// 子类中父类那部分内存用SmartDevice(n)构造
class Light : public SmartDevice {
public:
    Light(string n) : SmartDevice(n) {}
    void activate() {
        cout << "The Light is activate ! " << endl;
    }
};

class Fan : public SmartDevice {
public:
    Fan(string n) : SmartDevice(n) {}
    void activate() {
        cout << "The Fan is activate ! " << endl;
    }
};

int main() {
    vector<SmartDevice*> devptr;
    devptr.push_back(new Fan{"fan"});
    devptr.push_back(new Light{"light"});
    
    for(int i = 0; i < 2; i++) {
        devptr[i]->activate();
    }

    for (SmartDevice* d : devptr) delete d;

    return 0;
}
