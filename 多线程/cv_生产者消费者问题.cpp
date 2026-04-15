#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;                 // 全局互斥锁，保护共享队列
std::condition_variable not_full;   // 缓冲区未满时唤醒生产者
std::condition_variable not_empty;  // 缓冲区非空时唤醒消费者
std::queue<int> buffer;         // 共享缓冲区
const int MAX_SIZE = 5;         // 缓冲区最大容量

// 生产者线程函数
void producer() {
    for (int i = 1; i <= 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx); // 1. 先拿锁
        
        // wait 内部会：a.解锁 b.阻塞 c.醒来后重新抢锁
        // wait(mutex, logi_expression)
        // logi_expression = true: 继续执行
        //                   False， 解锁，并睡眠，放入not_full
        not_full.wait(lock, [] { return buffer.size() < MAX_SIZE; });     // 让当前线程在 not_full 上等待，直到“缓冲区没满”
        buffer.push(i);
        std::cout << "生产者放入: " << i << " (当前规模: " << buffer.size() << ")" << std::endl;

        // 3. 放完货后，通知等待“非空条件”的消费者
        not_empty.notify_one(); 
        
        // lock 在这里执行完会自动析构释放

        // 给消费者一点抢锁的时间
        lock.unlock(); // 手动提前解锁
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); 
    }
}

// 消费者线程函数
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx); // 1. 先拿锁

        // 2. 只要空了，就在 not_empty 上等待
        not_empty.wait(lock, [] { return !buffer.empty(); });

        int data = buffer.front();
        buffer.pop();
        std::cout << "消费者取走: " << data << std::endl;

        // 3. 取完货后，通知等待“未满条件”的生产者
        not_full.notify_one();

        if (data == 10) break; // 演示结束条件
    }
}


int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}