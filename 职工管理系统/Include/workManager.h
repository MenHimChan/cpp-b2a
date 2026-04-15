#pragma once
#include <iostream>
#include <worker.h>
#include <fstream>
#include <istream>
#define FILE_NAME "empFile.txt"

using namespace std;

class WorkerManager {
public:
    WorkerManager();
    ~WorkerManager();

    void showMenu();
    void exitSystem();
    void addEmp();
    void showEmp();
    void save();
    void Del_Emp();
    bool isExist(uint32_t id);

private:
    Worker** m_EmpArray;    // 堆区员工指针数组
    uint32_t m_EmpNum;      // 员工数量
};
