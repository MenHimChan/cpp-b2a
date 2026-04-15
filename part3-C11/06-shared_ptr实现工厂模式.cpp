#include <bits/stdc++.h>

using namespace std;


class Sensor {
public:
    virtual void collect() = 0;
    virtual ~Sensor() {cout << "Sensor Base deconstruct ! " << endl;}
};

class TempSensor : public Sensor {
public:
    void collect() override {cout << "collecting the temp data...." << endl;}
    ~TempSensor() {cout << "TempSensor deconstruct ! " << endl;}
};

class HumiditySensor : public Sensor {
public:
    void collect() override {cout << "collecting the Humid data...." << endl;}
    ~HumiditySensor() {cout << "HumiditySensor deconstruct ! " << endl;}
};

// 硬件只需要初始化一次： 单例模式
// 生产出来的实例要被不同的地方共享所有权： shared_ptr
class SensorFactory {
public:
    enum class Type { Temp, Humid };

    // 返回 shared_ptr，这样多个地方可以同时持有这个唯一的传感器
    static std::shared_ptr<Sensor> getSensor(Type type) {
        // 使用 static 局部变量，确保只初始化一次
        static std::shared_ptr<Sensor> tempInstance = std::make_shared<TempSensor>();
        static std::shared_ptr<Sensor> humidInstance = std::make_shared<HumiditySensor>();

        if (type == Type::Temp) return tempInstance;
        if (type == Type::Humid) return humidInstance;
        return nullptr;
    }
};

void testUnique() {
    auto uptr = SensorFactory::getSensor(SensorFactory::Type::Temp);
    uptr->collect();
    // 函数结束，uptr 自动释放，零开销
}

void testShared() {
    // 自动转换：unique_ptr -> shared_ptr
    std::shared_ptr<Sensor> sptr = SensorFactory::getSensor(SensorFactory::Type::Humid);
    std::cout << "Usage count: " << sptr.use_count() << std::endl; // 输出 1
    
    auto sptr2 = sptr; // 拷贝，计数加 1
    std::cout << "Usage count: " << sptr.use_count() << std::endl; // 输出 2
}

int main() {
    testUnique();
    return 0;
}