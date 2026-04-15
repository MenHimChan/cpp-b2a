#include <iostream>

using namespace std;

class CPU {
public:
    virtual void calculate() = 0;
    virtual ~CPU() = default;
};

class GPU {
public:
    virtual void display() = 0;
    virtual ~GPU() = default;
};

class Memory {
public:
    virtual void storage() = 0;    
    virtual ~Memory() = default;
};

class IntelCPU : public CPU {
public:
    void calculate() override {
        cout << "IntelCPU is calculating ! " << endl;
    }
};

class LenvoCPU : public CPU {
public:
    void calculate() override {
        cout << "LenvoCPU is calculating ! " << endl;
    }
};

class IntelGPU : public GPU {
public:
    void display() override {
        cout << "IntelGPU is displaying ! " << endl;
    }
};

class LenvoGPU : public GPU {
public:
    void display() override {
        cout << "LenvoGPU is displaying ! " << endl;
    }
};

class IntelMemory : public Memory {
public:
    void storage() override {
        cout << "IntelMemory is storageing ! " << endl;
    }
};

class LenvoMemory : public Memory {
public:
    void storage() override {
        cout << "LenvoMemory is storageing ! " << endl;
    }
};

class Computer {
private:
    CPU* m_cpu;
    GPU* m_gpu;
    Memory* m_mem;

public:
    Computer(CPU* cpu, GPU* gpu, Memory* mem) : m_cpu(cpu), m_gpu(gpu), m_mem(mem) {
        cout << "Calling Computer Constructor ! " << endl;
    }

    void running() {
        cout << "The computer is working ! " << endl;
        m_cpu->calculate();
        m_gpu->display();
        m_mem->storage();
    }

    ~Computer() {
        if(m_cpu != nullptr) {
            delete m_cpu;
            m_cpu = nullptr;
        }
        if(m_gpu != nullptr) {
            delete m_gpu;
            m_gpu = nullptr;
        }
        if(m_mem != nullptr) {
            delete m_mem;
            m_mem = nullptr;
        }
        cout << "Calling Computer deconstructor ! " << endl;
    }
};

int main() {
    Computer computer(new IntelCPU, new LenvoGPU, new IntelMemory);
    computer.running();
    return 0;
}