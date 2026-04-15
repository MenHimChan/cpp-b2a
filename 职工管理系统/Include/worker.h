#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
    virtual void showInfo() = 0;        // 显示职工信息
    virtual string getDeptName() = 0;   // 获取职工部门名称
    virtual ~Worker() {}                // 虚析构函数，保证删除子类对象时能正确调用子类的析构函数

    uint32_t m_id;
    string m_name;
    uint32_t m_did;          // 部门编号

protected:
    Worker(int id, string name, uint32_t did) 
        : m_id(id), m_name(name), m_did(did) {}
};