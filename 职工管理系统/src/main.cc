#include "workManager.h"
#include "manager.h"
#include "boss.h"
#include "employee.h"
#include <iostream>
#include <cstdint>

int main() {
    short choice = 0;
    WorkerManager wm;

    // 
    // wm.addEmp();
    // wm.showEmp();
    // return 0;

    // 多态调试
    // Worker* ptr = new Boss{0, "老虎", 0};
    // cout << ptr->getDeptName() << endl;
    // ptr->showInfo();
    // ptr = new Manger{1, "陈老猫", 1};
    // cout << ptr->getDeptName() << endl;
    // ptr->showInfo();
    // cout << ptr->m_name << endl;
    // return 0;

    while (true) {
        wm.showMenu();
        std::cout << "请输入您的选择: ";
        std::cin >> choice;
        switch (choice) {
            case 0:         // 退出系统
                system("read -p \"Press Enter to confirm...\" dummy");                
                wm.exitSystem();
                break;
            case 1:         // 增加职工信息
                wm.addEmp();
                break;
            case 2:         // 显示当前职工信息
                wm.showEmp();
                break;
            case 3:         // 删除离职职工
                wm.Del_Emp();
                break;
            case 4:         // 修改职工信息
                break;
            case 5:         // 查找职工信息
                break;         
            case 6:         // 按照编号排序
                break;   
            case 7:         // 清空所有文档
                break;       
            default:
                system("clear");     // 清屏
        }
    }
    return 0;
}