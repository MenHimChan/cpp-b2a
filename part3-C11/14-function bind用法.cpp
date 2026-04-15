#include <bits/stdc++.h>

using namespace std;

class Button {
private:
public:
    function<void()> onClick;
    void click() {
        if(onClick) onClick();
    }
};

// 业务逻辑 1
void playsound(string soundname, int volume) {
    cout << "播放声音: " << soundname << ", 音量: " << volume << endl;
}

// 业务逻辑 2： 某个玩家类的成员函数
class Player {
public:
    void jump() { cout << "玩家跳跃！" << endl; }
};

void test() {
    unique_ptr<Button> btn1 = make_unique<Button>();
    unique_ptr<Button> btn2 = make_unique<Button>();
    Player myPlayer;

    // ==========================================
    // 1：把多参数降为无参数
    // ==========================================
    // btn1->onClick = playsound;                       // 报错
    btn1->onClick = bind(playsound, "123.mp3", 100);    // ✅ 用 bind 填好参数，改造成 void()，装进 function

    // ==========================================
    // 黄金配合 2：驯服成员函数（抹平 this 指针差异）
    // ==========================================
    // btn2.onClick = &Player::jump;                // ❌ 报错！成员函数带有隐藏的 this，对不上！
    btn2->onClick = bind(&Player::jump, &myPlayer); // ✅ 用 bind 把 this 指针（&myPlayer）绑上去，改造成 void()，装进 function
}

int main() {
    test();
    return 0;
}