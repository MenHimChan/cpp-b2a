#include <bits/stdc++.h>

using namespace std;

// 1 function 用途： 预留通用接口
// 一个通用的 Button（按钮）类。
// 【quesiton】 ： 作为底层开发者，你根本不知道用户点击这个按钮时，是想“开火”、想“退出游戏”、还是想“提交表单”。
// 【Answer】： 在Button类里留一个 std::function 接口，让外面的使用者自己把逻辑插进来。
// 这就好比你造了一个带 USB 接口的插座，别人插什么设备你都不关心，通电就行。
class Button {
public:
    // 留一个通用接口：没有参数，没有返回值
    std::function<void()> onClick;
    void click() {
        cout << "按钮被按下了！" << endl;
        if (onClick) {
            onClick(); // 执行外部插进来的逻辑
        }
    }
};

void test01() {
    // 使用预留的通用接口
    unique_ptr<Button> exit_button = make_unique<Button>();
    exit_button->onClick = [] () {
        cout << "Exit game ! " << endl;
    };
    exit_button->click();           // Exit game ! 
}

void test02() {
    // 任务队列：可调用对象包装成统一类型存入队列，稍后执行
    // 
    vector<std::function<void()>> taskQueue;
    taskQueue.push_back([]() { cout << "正在下载文件..." << endl; });

    // 塞入任务2：带捕获的 Lambda
    int image_id = 9527;
    taskQueue.push_back([image_id]() { cout << "正在压缩图片 ID: " << image_id << endl; });

    // 后台统一执行（假装这是在另一个线程）
    cout << "--- 后台线程开始工作 ---" << endl;
    for (auto& task : taskQueue) {
        task(); // 挨个执行，管你里面是什么逻辑
    }
}

int main() {
    // test01();
    test02();
    return 0;
}
