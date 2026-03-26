#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;

// 题目：JLU 智能指令控制单元 (SensorControl)
// 1. 基础结构：
// 创建一个 SensorControl 类。
// 类内嵌套枚举 DeviceStatus：成员包括 IDLE=0, SAMPLING=5, ERROR=10。
// 类内起别名：typedef DeviceStatus State;
// 类外起别名：typedef unsigned char byte;
// 2. 唯一成员变量：
// byte m_config; （用于存放当前设备的 8 位指令/状态值）。
// 3. 核心函数功能（重点看这里）：
// void setMode(State s)：
// 作用：根据传入的枚举状态，更新 m_config 的值。
// 逻辑：把枚举 s 代表的数字存入 m_config。
// void loadConfig(byte b)：
// 作用：模拟接收外部传入的一个原始字节。
// 逻辑：把字节 b 存入 m_config，并必须用二进制（如 0b00001010）格式打印出来。
// byte execute()：
// 作用：检查当前的 m_config 是否安全。
// 逻辑：如果 m_config 的值恰好等于错误码 10，返回 1（表示报错）；否则返回 0（表示正常）。

typedef uint8_t mybyte;

class SensorControl {
public:
    enum DeviceStatus : uint8_t {
        IDLE = 0,
        SAMPLING = 5,
        ERROR = 10
    };

    SensorControl() : m_config(IDLE) {} // 构造函数初始化 m_config

    void setMode(DeviceStatus s) {
        m_config = s;
        cout << "Mode set to: " << bitset<8>(m_config) << endl; // 打印二进制形式
    }

    void loadConfig(DeviceStatus b) {
        m_config = b;           // 将当前状态存储到 m_config 中
        cout << "Loaded config: " << bitset<8>(b) << endl; // 打印二进制形式
    }

    mybyte execute() {
        if (m_config == ERROR) {
            cout << "Error state detected!" << endl;
            return 1; // 返回 1 表示错误状态
        }
        return 0; // 返回 0 表示正常状态
    }

private:
    DeviceStatus m_config;
};


int main() {
    SensorControl sensor;
    sensor.setMode(SensorControl::SAMPLING); // 设置状态为 SAMPLING
    sensor.loadConfig(SensorControl::IDLE); // 加载配置并打印二进制形式
    sensor.loadConfig(SensorControl::ERROR);
    sensor.execute(); // 执行并检查状态
    cout << sensor.IDLE << endl; // 打印 IDLE 的值
    return 0;
}
