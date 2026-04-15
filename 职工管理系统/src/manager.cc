#include "manager.h"

Manger::Manger(uint32_t id, string name, uint32_t did) : Worker(id, name, did)
{

}

void Manger::showInfo() {
    cout << "职工编号: " << this->m_id
            << "\t职工姓名: " << this->m_name
            << "\t岗位: " << this->getDeptName()
            << "\t岗位职责: 接收老板的任务，分配任务给员工" << endl;
}


string Manger::getDeptName() {
    return string("经理");
}
