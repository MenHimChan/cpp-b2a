#include <memory>
#include <iostream>
#include <thread>
#include <chrono>

// 全局int智能指针，指向18，被不同线程共享
std::shared_ptr<int> gInt = std::make_shared<int>(18);

void t1() {
    std::shared_ptr<int> pInt = gInt;           
    std::cout << "pInt use_count " << pInt.use_count() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void t2()
{
    std::weak_ptr<int> wInt(gInt);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::shared_ptr<int> sp = wInt.lock();          // 使用前先检查是否还有效
    if (sp)
    {
        std::cout << "sp use_count " << sp.use_count() << std::endl;
    }
    else
    {
        std::cout << "invalid " << std::endl;
    }
}

int main()
{
    std::thread th1(t2);            // 创建子线程th1，执行函数t2    
    std::thread th2(t1);            // 创建子线程th2，执行函数t1

    th1.join();
    th2.join();

    return 0;
}